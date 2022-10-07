// This program shows off the basics of RAII with locks

#include <mutex>
#include <thread>
#include <iostream>

// mutex
std::mutex mutex;

// Function executed by multiple threads
void print_func() {
  mutex.lock();
  std::cout << "Printing from a thread!\n";
  mutex.unlock();
}

// Function executed by multiple threads but with a lock guard
void better_print_func() {
  std::lock_guard<std::mutex> g(mutex);
  std::cout << "Printing from a thread!\n";
}

int main() {
  // Call our old-fashioned function
  std::thread t1(print_func);
  std::thread t2(print_func);
  t1.join();
  t2.join();

  // Call our better function using RAII
  std::thread t3(better_print_func);
  std::thread t4(better_print_func);
  t3.join();
  t4.join();

  return 0;
}