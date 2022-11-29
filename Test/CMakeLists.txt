cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(
        /usr/local/include/
        /usr/include/
        /opt/rh/devtoolset-11/root/usr/include/c++/11
        ../Lib/Tool)

ADD_SUBDIRECTORY(Tec/Cmake)

add_executable(zymem "")
# 头文件路径
TARGET_INCLUDE_DIRECTORIES(zymem PUBLIC ../Lib/Memory)
# 源文件
TARGET_SOURCES(zymem PUBLIC Memory/allocator_demo.cc)

add_executable(zycontainer "")
TARGET_INCLUDE_DIRECTORIES(zycontainer PUBLIC ../Lib/Container ../Lib/Tool)
TARGET_SOURCES(zycontainer PUBLIC Container/main.cc)

add_executable(zypool "")
TARGET_INCLUDE_DIRECTORIES(zypool PUBLIC ../Lib/Pool ../Lib/Tool ../Lib/Memory)
TARGET_SOURCES(zypool PUBLIC Pool/main.cc)
TARGET_LINK_LIBRARIES(zypool PUBLIC pthread)

ADD_EXECUTABLE(thrd_timeout "")
TARGET_SOURCES(thrd_timeout PUBLIC thread_timeout/thread_timeout.cc)
TARGET_LINK_LIBRARIES(thrd_timeout PUBLIC pthread)

add_executable(test1 Tec/继承/子类父类方法.cc)
add_executable(Deamon Deamon/Deamon.cc)
add_executable(enumclass Cpp/enumclass.cc)
add_executable(singleton Tool/singleton.cc)

add_executable(thread Thread/main.cc)
TARGET_INCLUDE_DIRECTORIES(thread PUBLIC ../Lib/Thread)
TARGET_LINK_LIBRARIES(thread PUBLIC pthread)

add_executable(timer Tool/timer.cc)
TARGET_INCLUDE_DIRECTORIES(timer PUBLIC ../Lib/Tool ../Lib/Thread)
TARGET_LINK_LIBRARIES(timer PUBLIC pthread)
