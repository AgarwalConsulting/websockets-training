#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// vector<int> collect(vector<int> in, int (*op) (int)) {
vector<int> collect(vector<int> in, const function<int(int)> &op) {
  vector<int> out = {};

  for (auto& el : in) {
    out.push_back(op(el));
  }

  return out;
}

// int doublee(int x)
// {
//   return x*2;
// }

int main()   {
  vector<int> primes = {1, 2, 3, 5, 7, 11};

  int scaleBy = 2;

  vector<int> doubled = collect(primes, [scaleBy](int i) {
  // vector<int> doubled = collect(primes, [](int i) {
    // return i * 2;
    return i * scaleBy;
  });

  //vector<int> doubled = collect(primes, &doublee);

  for (const int& el: doubled) {
  // for (auto& el: doubled) {
    cout << el << " ";
  }

  cout << endl;
}
