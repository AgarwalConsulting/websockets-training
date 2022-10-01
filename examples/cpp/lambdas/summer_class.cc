#include <functional>
#include <iostream>
#include <stdio.h>

using namespace std;

class Sum {
  public:
  Sum() {
    cout << "Created!\n";
  }

  // Sum(Sum &obj) {
  //   cout << "Copy Created!\n";
  //   value = obj.value;
  // }

  // Sum(Sum&& obj) noexcept {
  //   cout << "Move Created!\n";
  //   value = obj.value;
  // }

  ~Sum() {
    cout << "Deallocated!" << value << "\n";
  }

  void IncrementBy(int x) {
    value = value + x;
  }

  int Value() {
    return value;
  }

  private:
    int value = 0;
};

const function<int(int)> summer() {
  // int sum = 0; // When does this get deallocated?
  Sum sum;

  printf("%p\n", &sum);

  cout << "creating anonymous!\n";

  return [sum](int x) mutable -> int { // x = 20 | sum = 11
    cout << "calling anonymous!\n";

    printf("%p\n", &sum);

    sum.IncrementBy(x);
    return sum.Value();
  };
}

void test(const function<int(int)> &fn) {
  cout << fn(1) << "\n";
}

int main() {
  auto sum1 = summer(); // Type: ?

  cout << "first call!\n";

  cout << sum1(11) << "\n"; // Value: 11 | Line: L9

  test(sum1); // Value: 12 | Line: L9

  // cout << sum1(11) << "\n"; // Value: 22 | Line: L9
  cout << sum1(11) << "\n"; // Value: 23 | Line: L9

  cout << "Exiting main!\n";

  // while (true) {

  // }

  return 0;
}
