//
// Created by 霍伟元 on 2022/10/3.
//

#include <iostream>
#include "zyThrdPool.h"
#include "zyAllocator.h"
using namespace std;
zy::Allocator *g_alloc = new zy::Allocator();

void test(int time) {
//  std::this_thread::sleep_for(std::chrono::seconds(time));
  cout << "test " << time << endl;
//  return time;
}

void start_thrd(zy::ThrdPool *pool) {
  if (!pool->isTerminate()) return;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  pool->start();
}

void stop_thrd(zy::ThrdPool *pool) {

  if (pool->isTerminate()) return;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  pool->stop();
}

int main()
{
  zy::ThrdPool *pool1 = zy::g_new<zy::ThrdPool>(g_alloc, 3);
  zy::ThrdPool *pool = zy::g_new<zy::ThrdPool>(g_alloc, 10);

  pool1->exec([&pool] {
    if (!pool->isTerminate()) return;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "start " << endl;
    pool->start();
  });

  pool1->exec([&pool] {
    if (pool->isTerminate()) return;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "stop " << endl;
    pool->stop();
  });

  pool1->exec([&pool] {
    int r = 0;
    while ((r = pool->wait(1))) {
      cout << "timeout " << r << endl;
    }
  });

  pool1->start();

  for (int i = 0; i < 1000; ++i) {
    auto ret = pool->exec(1, test, i);
    ret.get();
  }

  pool1->stop();
  pool->stop();

  return 0;
}
