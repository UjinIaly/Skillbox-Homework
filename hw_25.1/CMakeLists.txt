cmake_minimum_required(VERSION 3.23)
project(hw_25_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw_25_1 src/main.cpp include/func.h)
target_include_directories(hw_25_1 PUBLIC include)