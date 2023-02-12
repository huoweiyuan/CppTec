cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(
        /usr/local/include/
        /usr/include/
        /opt/rh/devtoolset-11/root/usr/include/c++/11
        ../Lib/Utillity)

ADD_SUBDIRECTORY(Tec/Cmake)

add_executable(zymem "")
# 头文件路径
TARGET_INCLUDE_DIRECTORIES(zymem PUBLIC ../Lib/Memory)
# 源文件
TARGET_SOURCES(zymem PUBLIC Memory/allocator_demo.cc)

add_executable(zycontainer "")
TARGET_INCLUDE_DIRECTORIES(zycontainer PUBLIC ../Lib/Container ../Lib/Utillity)
TARGET_SOURCES(zycontainer PUBLIC Container/main.cc)

add_executable(zypool "")
TARGET_INCLUDE_DIRECTORIES(zypool PUBLIC ../Lib/Pool ../Lib/Utillity ../Lib/Memory)
TARGET_SOURCES(zypool PUBLIC Pool/main.cc)
TARGET_LINK_LIBRARIES(zypool PUBLIC pthread)

ADD_EXECUTABLE(thrd_timeout "")
TARGET_SOURCES(thrd_timeout PUBLIC thread_timeout/thread_timeout.cc)
TARGET_LINK_LIBRARIES(thrd_timeout PUBLIC pthread)

add_executable(Deamon Deamon/Deamon.cc)
add_executable(enumclass Cpp/enumclass.cc)
add_executable(singleton Utillity/singleton.cc)

add_executable(thread Thread/main.cc)
TARGET_INCLUDE_DIRECTORIES(thread PUBLIC ../Lib/Thread)
TARGET_LINK_LIBRARIES(thread PUBLIC pthread)

add_executable(timer Utillity/timer.cc)
TARGET_INCLUDE_DIRECTORIES(timer PUBLIC ../Lib/Utillity ../Lib/Thread)
TARGET_LINK_LIBRARIES(timer PUBLIC pthread)

#add_custom_command(TARGET timer PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E echo Teeeeest1)

# ADD_CUSTOM_TARGET(Parser echo "Creating parser")

# ADD_CUSTOM_COMMAND(TARGET Parser PRE_BUILD
#         COMMAND flex ${PROJECT_SOURCE_DIR}/Test/flex_bison/config.l -o ${PROJECT_SOURCE_DIR}/Test/flex_bison/config.yy.c
# #        COMMAND bison -d flex_bison/config.y
#         COMMAND ls
#         COMMAND ${CMAKE_COMMAND} -E echo compile finish
#         COMMENT Building flex and bison
#         VERBATIM
#         )

# ADD_DEPENDENCIES(timer Parser)


add_executable(test1 Tec/继承/子类父类方法.cc)
add_executable(volatile Tec/volatile/volatile.cc)

add_executable(zyleak "")
# 头文件路径
TARGET_INCLUDE_DIRECTORIES(zyleak PUBLIC ../Lib/Memory)
# 源文件
TARGET_SOURCES(zyleak PUBLIC Memory/leak_check.cc)

#ADD_SUBDIRECTORY(flex_bison)

add_executable(zynotify iNotify/main.cc)
