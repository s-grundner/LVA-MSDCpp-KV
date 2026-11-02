cmake_minimum_required(VERSION 3.10)

project(intro)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the executable
add_executable(
  intro
  src/main.cpp
  src/computer.cpp
  src/cloudserver.cpp
  src/cloud.cpp
)

# include headers
target_include_directories(intro PRIVATE inc)
