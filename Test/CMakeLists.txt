cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 14)

#SET(CMAKE_BUILD_TYPE Debug)

SET(MEM_SRC Memory/allocator_demo.cc)
add_executable(zymem ${MEM_SRC})
#TARGET_SOURCES(zymem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Memory/allocator_demo.cc)
# 头文件路径
TARGET_INCLUDE_DIRECTORIES(zymem PUBLIC ../Lib/Memory)


