cmake_minimum_required(VERSION 3.25)
project(list_template)

set(CMAKE_CXX_STANDARD 23)

add_executable(list_template main.cpp list.h stack.h queue.h)
