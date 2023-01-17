#include <chrono>
#include <iostream>
#include <thread>

#include "coredumper/coredumper.h"

using namespace std::chrono_literals;

static constexpr auto threadSleepDuration = 5s;
static constexpr auto writeCoredumpDuration = 3s;

int main(int argc, char *argv[]) {
  auto threadWait = []{
      std::this_thread::sleep_for(threadSleepDuration);
  };
  std::cout << "Start thread waiting for " << threadSleepDuration.count() << " seconds." << std::endl;
  auto waitThread = std::thread(threadWait);
  std::this_thread::sleep_for(writeCoredumpDuration);
  std::cout << "Writing core dump after " << writeCoredumpDuration.count() << " seconds." << std::endl;
  int result = WriteCoreDump("./core_example.dump");
  std::cout << "WriteCoreDump returned with result: " << result << " and errno: " << errno <<std::endl;
  std::cout << "Wait for thread to join..." <<std::endl;
  waitThread.join();
}