cmake_minimum_required(VERSION 3.20)
project(oop_labs)

set(This oop_labs)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()
add_subdirectory(googletest)

set(Headers BigInt.h)
set(Sources main.cpp BigInt.cpp)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(test)
