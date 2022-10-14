//
// Created by 霍伟元 on 2022/10/1.
//

#include "zy_string.h"
#include <utility>
#include <iostream>

using zy::String;
using namespace std;

int main()
{
  String s1 = "你好",s2,s3;
  cout << s1.c_str() << endl;
  s2 = s3;
  s1 = std::move(s2);
  cout << s1.c_str() << endl;
  return 0;
}