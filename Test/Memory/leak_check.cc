//
// Created by 霍伟元 on 2022/12/1.
//

#include "zyDebugMemLeak.h"

using namespace zy;
DebugMemLeak gDebugMemLeak;

int main(int args, char **argv)
{
  char *s = static_cast<char*>(g_alloc(&gDebugMemLeak, 10));
  s[-9] = 'a';
  // g_free(s);
  return 3;
}