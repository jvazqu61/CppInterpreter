cmake_minimum_required(VERSION 3.17)
project(project4)

set(CMAKE_CXX_STANDARD 14)

add_executable(project4 main.cpp node.h node.cpp LList.h LList.cpp ro_mem.h ro_mem.cpp splInstructions.h splInstImplement.cpp splInstImplement.h splInterpreter.h splInterpreter.cpp)