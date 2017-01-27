cmake_minimum_required(VERSION 3.6)
project(Final_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp employee.cpp employee.h employeeDB.cpp employeeDB.h)
add_executable(Final_Project ${SOURCE_FILES})