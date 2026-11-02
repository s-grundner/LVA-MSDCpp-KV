cmake_minimum_required(VERSION 3.22)

project(k3b1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable( k3b1_1
  src/k3b1_1.cpp
  src/k3b1_1_toplevel.cpp
  src/k3b1testbench.cpp
  src/k3b1movingaverage.cpp
)

                                                                                
add_executable( k3b1_3
  src/k3b1_3.cpp
  src/k3b1_3_toplevel.cpp
  src/k3b1testbench.cpp
  src/k3b1movingaverage.cpp
)

target_include_directories(k3b1_1 PRIVATE inc)
target_include_directories(k3b1_3 PRIVATE inc)
target_link_libraries(k3b1_1 systemc m)
target_link_libraries(k3b1_3 systemc m)
