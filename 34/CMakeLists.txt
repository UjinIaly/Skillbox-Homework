cmake_minimum_required(VERSION 3.26)
project(34)

set(CMAKE_PREFIX_PATH "/usr")

find_package(Qt5Widgets REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(34 main.cpp)
target_link_libraries(34 Qt5::Widgets)
