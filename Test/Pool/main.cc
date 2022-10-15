//
// Created by 霍伟元 on 2022/10/3.
//

#include <iostream>
#include "zy_thrd_pool.h"
#include "zy_allocator.h"
using namespace std;
zy::Allocator *g_alloc = new zy::Allocator();

int test(int time) {
//  std::this_thread::sleep_for(std::chrono::seconds(time));
  cout << "test " << time << endl;
  return time;
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
    pool->start();
  });

  pool1->exec([&pool] {
    if (pool->isTerminate()) return;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    pool->stop();
  });

  pool1->exec([&pool] {
    int r = 0;
    while ((r = pool->wait(1))) {
      cout << "timeout " << r << endl;
    }
  });

  pool1->start();

//  pool->start();
  for (int i = 0; i < 1000; ++i) {
    std::future<int> ret = pool->exec(1, test, i);
  }

  pool1->stop();
  pool->stop();

//  pool->stop();

//  int r = 0;
//  while ((r = pool->wait(1))) {
//    cout << "timeout " << r << endl;
//    if (pool->isTerminate()) {
//      pool->start();
//    }
//  }
//  try {
//    cout << "timeout " << pool->wait(1000) << endl;
//    cout << ret.get() << endl;
//  } catch (std::future_error &e) {
//    cout << "catch error:" << e.code() << "," << e.what() << endl;
//  }
  return 0;
}