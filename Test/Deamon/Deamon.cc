//
// Created by 霍伟元 on 2022/10/12.
//

#include "zyService.h"
using namespace zy;
using namespace utillity;
int test_main(int a, const char *msg) {
//  while (1) {
    std::cout << a << " " << msg << std::endl;
    sleep(1);
//  }
  return 1;
}

void test_main1(int a, const char *msg, int b) {
  while (1) {
    std::cout << a << " " << msg << " " << b << std::endl;
    sleep(1);
  }
}

void test_main2() {
//  return 0;
}

int main() {
  Daemonize(test_main1, 1, "asd", 2);
  return 0;
}
