cmake_minimum_required(VERSION 3.4)
project(TCPL4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TCPL4 ${SOURCE_FILES})