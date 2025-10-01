cmake_minimum_required(VERSION 3.10)
project(TODOLIST)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(todo
    source/main.cpp
    include/Task.cpp
)
