cmake_minimum_required(VERSION 3.25)
project(complex_number)

set(CMAKE_CXX_STANDARD 23)

add_executable(complex_number main.cpp header.h functions.cpp test.cpp test.h)
