//
// Created by 霍伟元 on 2022/10/12.
//

#include "Service.h"
int test_main(int a, const char *msg) {
  while (1) {
    std::cout << a << " " << msg << std::endl;
    sleep(1);
  }
  return 0;
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
//  return Daemonize<int, int, const char*>(nullptr, std::function<int(int, const char*)>(test_main), 1, "你好");
//  return Daemonize<int, int, const char*, int>(nullptr, std::function<int(int, const char*, int)>(test_main1), 1,
//    "你好", 2);
//  Daemonize<int, const char*, int>(nullptr, std::function<void(int, const char*, int)>(test_main1),  1, "你好", 2);
  Daemonize()
  return 0;
}