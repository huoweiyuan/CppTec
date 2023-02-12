#include <sys/inotify.h>
#include <iostream>
#include <cerrno>
#include <cstdio>
#include <limits.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include "zyNotify.h"

using namespace zy;

void judgeEventName(uint32_t mask, std::string &event)
{
  if(mask & IN_ACCESS)        event = "IN_ACCESS";
  else if(mask & IN_ATTRIB)        event = "IN_ATTRIB";
  else if(mask & IN_CLOSE_WRITE)   event = "IN_CLOSE_WRITE";
  else if(mask & IN_CLOSE_NOWRITE) event = "IN_CLOSE_NOWRITE";
  else if(mask & IN_CREATE)        event = "IN_CREATE";
  else if(mask & IN_DELETE_SELF)   event = "IN_DELETE_SELF";
  else if(mask & IN_MODIFY)        event = "IN_MODIFY";
  else if(mask & IN_MOVE_SELF)     event = "IN_MOVE_SELF";
  else if(mask & IN_MOVED_FROM)    event = "IN_MOVED_FROM";
  else if(mask & IN_MOVED_TO)      event = "IN_MOVED_TO";
  else if(mask & IN_OPEN)          event = "IN_OPEN";
  else if(mask & IN_IGNORED)       event = "IN_IGNORED";
  else if(mask & IN_ISDIR)         event = "IN_ISDIR";
  else if(mask & IN_UNMOUNT)       event = "IN_UNMOUNT";
  else                        event = "UNKNOW";
}

class HandlerTest : public Handler<char>
{
 public:
   int handing(char *data) override
   {
     std::cout << data << std::endl;
     return 0;
   }
};

class NotifyTest : public Notify
{
};

int main(int argc, char **argv)
{
  HandlerTest *handler = new HandlerTest();
  NotifyTest *notify = new NotifyTest();

  //初始化inotify
  int fd = inotify_init();
  if(fd == -1)
  {
    perror("initalize inotify failed");
    return -1;
  }

  //添加监控目录
  int wd;
  int watch_wd[100] = {0};
  for(int i = 1; i < argc; i++)
  {
    wd = inotify_add_watch(fd, argv[i], IN_ALL_EVENTS); //添加监控项目，监控所有事件
    if(wd < 0)
    {
      perror("add watch failed");
      return -1;
    }
    watch_wd[i] = wd;
  }

  //监听事件
  while(true)
  {
    char buf[(sizeof(struct inotify_event) + NAME_MAX + 1) * 10]; //最多支持10个文件同时发生事件
    bzero(buf, sizeof(buf));
    ssize_t numRead = read(fd, buf, sizeof(buf));
    if(numRead < 0)
    {
      perror("read inotify event failed");
      return -1;
    }

    char *p = NULL;
    struct inotify_event *event = NULL;

    for(p = buf; p < (buf + numRead); )
    {
      event = (struct inotify_event*)p;
      std::string event_name;
      judgeEventName(event->mask, event_name);
      // std::cout << event_name << std::endl;
      notify->notify(handler, const_cast<char*>(event_name.c_str()));

      p += sizeof(struct inotify_event) + event->len;
    }
  }

  return 0;
}
