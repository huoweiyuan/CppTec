#include <iostream>
#include "Timer.h"

using namespace std;
using namespace zy::tool;

class TimerTest : public Timer
{
  void testA()
  {
    cout << "testA" << endl;
  }

  void testB()
  {
    cout << "testB" << endl;
  }

  void testC()
  {
    cout << "testC" << endl;
  }

 public:
  TimerTest()
    : Timer(1000)
  {
    setTimer(1000, &TimerTest::testA, this);
    setTimer(2000, &TimerTest::testB, this);
    setTimer(3000, &TimerTest::testC, this);
  }
};

int main(int argc, char **argv)
{
  TimerTest test;
  test.start();
  test.join();
  return 0;
}
