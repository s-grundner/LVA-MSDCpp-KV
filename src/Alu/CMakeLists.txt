cmake_minimum_required(VERSION 3.22)

project(alu)
set(CMAKE_CXX_STANDARD 14)

add_executable(
  alu
	main.cpp
  alu.cpp
	testbench.cpp
)

target_link_libraries(alu systemc)
