cmake_minimum_required(VERSION 3.23)
project(hw_25_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw_25_2 src/main.cpp src/kbd.cpp include/kbd.h src/gpu.cpp include/gpu.h src/cpu.cpp include/cpu.h src/disk.cpp include/disk.h src/ram.cpp include/ram.h)
target_include_directories(hw_25_2 PUBLIC include)
