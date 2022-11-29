// Created by huoweiyuan on 11/29/22 9:37 PM
#include <string>

using namespace std;


class Test
{
 private:
  int a;
  int b;

 public:
  volatile Test& operator=(volatile Test &t) volatile
  {
    return *this;
  }
  Test() = default;
  Test(int _a, int _b)
    :a(_a), b(_b)
  {}
};

int main(int argc, char **argv)
{
  volatile Test  t1(1,2);
  Test t2;
  t1 = t2; // passing ‘volatile Test’ as ‘this’ argument discards qualifiers

  // this is ok
  // volatile int t1 = 0;
  // int t2 = 1;
  // t1 = t2;
  return 0;
}
