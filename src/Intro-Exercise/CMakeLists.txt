cmake_minimum_required(VERSION 3.10)

project(cpp_ex3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the executable
add_executable(cpp_ex3 src/main.cpp src/computer.cpp src/cloudserver.cpp src/cloud.cpp)

# include headers
target_include_directories(cpp_ex3 PRIVATE inc)
