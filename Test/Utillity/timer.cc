#include <iostream>
#include "zyTimer.h"

using namespace std;
using namespace zy::utillity;

class TimerTest : public TimerImpl
{
  void testA()
  {
    cout << "testA " << time(nullptr) << endl;
  }

  void testB()
  {
    cout << "testB " << time(nullptr) << endl;
  }

  void testC()
  {
    cout << "testC " << time(nullptr) << endl;
  }

 public:
  TimerTest()
    : TimerImpl(1000)
  {
    setTimer(1000, &TimerTest::testA, this);
    setTimer(2000, &TimerTest::testB, this);
    setTimer(3000, &TimerTest::testC, this);
  }
};

class TimerTest2 : public TimerImpl
{
  void testA()
  {
    cout << "testA " << time(nullptr) << endl;
  }

  void testB()
  {
    cout << "testB " << time(nullptr) << endl;
  }

  void testC()
  {
    cout << "testC " << time(nullptr) << endl;
  }
 public:
  TimerTest2()
    : TimerImpl(-1)
  {
    setTimer(1000, &TimerTest2::testA, this);
    setTimer(2000, &TimerTest2::testB, this);
    setTimer(3000, &TimerTest2::testC, this);
  }

  int thrd_routine(void) override
  {
    //
    cout << "DO MY THINGS" << endl;
    checkTimeExpire();
    return 0;
  }
};

int main(int argc, char **argv)
{
  TimerTest test;
  test.start();
  test.join();
  
  // TimerTest2 test;
  // test.start();
  // test.join();
  return 0;
}
