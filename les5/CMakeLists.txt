cmake_minimum_required(VERSION 3.5)

project(les5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(les5 main.cpp common.h)
