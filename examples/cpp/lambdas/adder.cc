#include<iostream>
#include <functional>

using namespace std;

const function<int(int)> adder(int by) {
  return [by](int x) {
    return x + by;
  };
}

string hello() {
  return "hello";
}

int sample() {
  return 42;
}

int main() {
  auto addBy2 = adder(2); // Type: int (*) (int)

  cout << addBy2(10) << "\n"; // Value: 12

  // cout << addBy2;

  // auto i = sample(); // Type: int

  // i = 'A'; // char to int

  // cout << i << "\n";

  // i = "A"; // string to int

  // cout << i << "\n";

  // auto s = hello(); // Type inference

  // cout << s << "\n";

  // s = 65;

  // cout << s << "\n";


  return 0;
}
