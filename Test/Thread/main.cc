#include "zy_thread.h"
#include <iostream>

using namespace std;
using namespace zy;

class ThreadImpl : public Thread
{
 public:
  ThreadImpl()
    : Thread(false)
  {
  }

  ~ThreadImpl() = default;

  int thrd_begin(void) override
  {
    cout << "thrdBegin" << endl;
    return 0;
  }

  int thrd_end(void) override
  {
    cout << "thrdEnd" << endl;
    return 0;
  }

  int thrd_routine(void) override
  {
    cout << "thrdRoutine" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
  }
};


class ThreadImpl2
{
 public:
  ThreadImpl2() = default;
  ThreadImpl2(Thread *thread)
  {
    thread->exec_routine(&ThreadImpl2::testA, this);
  }

 private:
  void testA()
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "testA" << time(nullptr) << endl;
  }
};

int main(int argc, char **argv)
{
  // ThreadImpl impl;
  // impl.start();
  // impl.join();


  Thread thread;
  ThreadImpl2 impl2(&thread);
  thread.start();
  thread.join();
  return 0;
}
