#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int x = 0; // data segment
std::mutex m; // data segment

void increment1() {
	m.lock();
	x++;

	cout<<"\nincrementer 1"<<endl;
	m.unlock();
}

void increment2() {
	m.lock();
	x++;

	cout<<"\nincrementer 2"<<endl;
	m.unlock();
}

int main() {
	std::thread t2(increment2);
	std::thread t1(increment1);

	t1.join();
	t2.join();

	cout<<x<<endl;
	return 0;
}
