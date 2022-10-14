//
// Created by 霍伟元 on 2022/10/6.
//


#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <time.h>

std::mutex g_mutex_wait;                 // 互斥锁
std::condition_variable g_cond_wait;     // 条件变量

void delay(int seconds)
{
  clock_t start = clock();
  clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;
  while ((clock() - start) < lay);
}

bool testDelayAPI(bool sign)
{
  if (sign) {
    long int num = 0;
    for (int i = 0; i < 10000000; i++) {
      num++;
    }
    g_cond_wait.notify_one();
    return true;
  }
  else {
    delay(5);
    int a = 5;
    return true;
  }

}

void testAPI()
{
  testDelayAPI(false);
}

int main(void)
{
  std::thread thread_input(testAPI);

  std::unique_lock<std::mutex> lockWait(g_mutex_wait);
  std::cv_status cvsts = g_cond_wait.wait_for(lockWait, std::chrono::seconds(1));

  // 消息接收超时
  if(cvsts == std::cv_status::timeout){
    std::cout << "超时！" << std::endl;
  }
  else // 接收到条件变量信号，未超时
  {
    time_t tmInputEnd = time(NULL);
    std::cout << "未超时" << std::endl;
  }
  thread_input.join();
  return 0;
}
