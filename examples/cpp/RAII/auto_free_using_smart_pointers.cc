#include <iostream>
#include <memory>

// A simple object with only constructor and destructor
class Sample{
  public:
  Sample()
  {
    std::cout << "Sample object created!\n";
  }
  ~Sample()
  {
    std::cout << "Sample object destroyed!\n";
  }
};

int main () {
  // If we use new/delete, the programmer manages the lifetime
  Sample *r1 = new Sample;
  // Free the Sample
  delete r1;

  // If we use smart pointers, they get freed automatically when
  // the pointer goes out of scope
  std::unique_ptr<Sample> r2(new Sample);

  return 0;
}
