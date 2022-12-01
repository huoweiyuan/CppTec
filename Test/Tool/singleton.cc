#include "zySingleton.h"
#include <iostream>

using namespace std;
using namespace zy::tool;

class A
{
 public:
  void show() const {
    cout << "A" << endl;
  }

  ~A() {
    cout << "~A" << endl;
  }
};

class B {
 public:
  void show() const {
    cout << "B" << endl;
  }
};

class C {
 private:
  char a[12];

 public:
  void show() const {
    cout << "C " << &a << endl;
    
  }
};

class D {
 public:
  D():a(0) {}
  D(int a):a(a){}
 private:
  int a;
 public:
  void show() const {
    cout << "D " << a << endl;
  }
};

int main(int argc, char **argv) {
  Singleton<A>::getInstance()->show();
  Singleton<B>::getInstance()->show();
  Singleton<C>::getInstance()->show();
  Singleton<C>::getInstance()->show();
  Singleton<D>::getInstance()->show();
  Singleton<D>::getInstance(2)->show();
  return 0;
}
