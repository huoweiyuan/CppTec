cmake_minimum_required(VERSION 3.16)
project(CppTec)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_BUILD_TYPE Debug)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
   LINK_DIRECTORIES("/opt/rh/devtoolset-11/root/usr/lib/gcc/x86_64-redhat-linux/11/")
ENDIF()

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
LINK_LIBRARIES(asan)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/Test)

