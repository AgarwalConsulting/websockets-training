#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady{false};

void waitingForWork() {
    std::cout << "Waiting " << std::endl;
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, []{ return dataReady; });   // (4)
    std::cout << "Running " << std::endl;
}

void setDataReady() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10000) );
    {
        std::lock_guard<std::mutex> lck(mutex_);
        dataReady = false;
    }
    std::cout << "Data prepared" << std::endl;
    condVar.notify_one();                        // (3)
}

int main() {
  std::cout << std::endl;

  std::thread t1(waitingForWork);               // (1)
  std::thread t2(setDataReady);                 // (2)

  t1.join();
  t2.join();

  std::cout << std::endl;
}
