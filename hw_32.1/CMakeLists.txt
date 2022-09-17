cmake_minimum_required(VERSION 3.23)
project(hw_32_1)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(hw_32_1 PRIVATE nlohmann_json::nlohmann_json)

add_executable(hw_32_1 main.cpp)
