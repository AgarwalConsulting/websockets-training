#include <functional>
#include <iostream>
#include <stdio.h>

using namespace std;

const function<int(int)> summer() {
  int sum = 0; // When does this get deallocated?

  // printf("%p\n", &sum);

  return [sum](int x) mutable -> int {
    // printf("%p\n", &sum);

    sum += x;
    return sum;
  };
}

int main() {
  auto sum1 = summer(); // Type: ?

  cout << sum1(11) << "\n"; // Value: ?
  cout << sum1(10) << "\n"; // Value: ?

  return 0;
}
