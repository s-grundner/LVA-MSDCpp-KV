cmake_minimum_required(VERSION 3.22)

project(alu)
set(CMAKE_CXX_STANDARD 14)

add_executable( k3b4
	k3b4.cpp
	k3b4alu.cpp
	k3b4testbench.cpp
)

target_link_libraries(k3b4 systemc)
