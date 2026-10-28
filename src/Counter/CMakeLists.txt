cmake_minimum_required(VERSION 3.22)

project(counter)
set(CMAKE_CXX_STANDARD 14)

include_directories (socket)

add_executable(counter 
  socket/Socket.h
  socket/Socket.cpp
  socket/SocketException.h
  socket/ServerSocket.h
  socket/ServerSocket.cpp
  counter.h
  stimGen.h
  stimGen.cpp
  display.h
  clockDisplay.h
  main.cc
)

target_link_libraries(counter systemc ncurses m)
