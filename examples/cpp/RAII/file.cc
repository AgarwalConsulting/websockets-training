// A simple example to show how RAII makes it easier to
// do file operations

#include <iostream>
#include <fstream>

// A simple wraper class for file operations
// Takes care of opening and closing the file
// here fstream is used for perfoming file operations
//fstream uses RAII under the hood
class loadFile {
public:
	loadFile(char const * filename) {
		file_.open(filename);
	}
	~loadFile(){
		file_.close();
		std::cout << "The file is closed\n";
	}
	void write(std::string const &s) {
		file_ << s;
	}
private:
	std::ofstream file_;
};


int main() {
	//usual way
	std::ofstream myfile1;
	myfile1.open("outputFile1.txt");
	myfile1 << "Writing into a txt file.\n";
	myfile1.close();

	//with RAII
	loadFile myfile2("outputFile2.txt");
	myfile2.write("Writing in a safe txt file.\n");
	myfile2.write("Writing again in a safe txt file.\n");
	return 0;
}
