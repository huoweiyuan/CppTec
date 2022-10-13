//
// Created by 霍伟元 on 2022/10/13.
//

#ifndef CPPTEC_LIB_TOOL_SERVICE_H_
#define CPPTEC_LIB_TOOL_SERVICE_H_

#include <functional>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

template<typename RetType, typename... ParamType>
RetType Daemonize(std::function<void(const char *err_msg)> error_callback,
                  std::function<RetType(ParamType...)> daemonize_main, ParamType&&... params)
{
  std::function<void(const char *msg)> _error_func;
  error_callback ?
    _error_func = error_callback :
    _error_func = [] (const char *err_msg) {
      std::cerr << err_msg << std::endl;
  };

  if (!daemonize_main) {
    _error_func("Main function is empty!");
    return -1;
  }

  // Create daemonize process
  pid_t pid = -1;
  if (-1 == (pid = fork())) {
    _error_func("Fork child process error!");
    return -1;
  }

  // Father process exit
  if (pid > 0) {
    exit(0);
  }

  // Create new session
  if (-1 == (pid = setsid())) {
    _error_func("Create new session error!");
    return -1;
  }

  umask(0);

  return daemonize_main(std::forward<ParamType>(params)...);
}

#endif //CPPTEC_LIB_TOOL_SERVICE_H_
