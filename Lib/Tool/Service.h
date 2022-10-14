//
// Created by 霍伟元 on 2022/10/13.
//

#ifndef CPPTEC_LIB_TOOL_SERVICE_H_
#define CPPTEC_LIB_TOOL_SERVICE_H_

#include <functional>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

template<typename... ParamType>
void Daemonize(std::function<void(const char *err_msg)> error_callback,
               std::function<void(ParamType...)> daemonize_main, ParamType&&... params)
{
  if (!error_callback) {
    error_callback = [] (const char *err_msg) {
      std::cerr << err_msg << std::endl;
    };
  }

  if (!daemonize_main) {
    error_callback("Main function is empty!");
  }

  // Create daemonize process
  pid_t pid = -1;
  if (-1 == (pid = fork())) {
    error_callback("Fork child process error!");
  }

  // Father process exit
  if (pid > 0) {
    exit(0);
  }

  // Create new session
  if (-1 == (pid = setsid())) {
    error_callback("Create new session error!");
  }

  umask(0);

  daemonize_main(std::forward<ParamType>(params)...);
}

template<typename RetType, typename... ParamType>
RetType Daemonize(std::function<void(const char *err_msg)> error_callback,
                  std::function<RetType(ParamType...)> daemonize_main, ParamType&&... params)
{
  if (!error_callback) {
    error_callback = [] (const char *err_msg) {
      std::cerr << err_msg << std::endl;
    };
  }

  if (!daemonize_main) {
    error_callback("Main function is empty!");
    return -1;
  }

  // Create daemonize process
  pid_t pid = -1;
  if (-1 == (pid = fork())) {
    error_callback("Fork child process error!");
    return -1;
  }

  // Father process exit
  if (pid > 0) {
    exit(0);
  }

  // Create new session
  if (-1 == (pid = setsid())) {
    error_callback("Create new session error!");
    return -1;
  }

  umask(0);

  return daemonize_main(std::forward<ParamType>(params)...);
}

#endif //CPPTEC_LIB_TOOL_SERVICE_H_
