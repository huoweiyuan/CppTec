cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)

add_custom_command(TARGET timer PRE_BUILD
        COMMAND echo Teeeeest)