cmake_minimum_required(VERSION 3.5)

project(les6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(les6 main.cpp stack_array.h priority_queue.h)
