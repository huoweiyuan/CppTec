//
// Created by 霍伟元 on 2022/10/9.
//
#include <iostream>
using namespace std;
class A
{
 public:
  void func(void) {
    cout << "A::func" << endl;
  }
};

class B : public A
{

};

int main() {
  B b;
  b.func();
  return 0;
}