cmake_minimum_required(VERSION 3.15)
project(CompileStack)

set(CMAKE_CXX_STANDARD 14)

add_executable(CompileStack main.cpp Stack.h StackArray.h Operator.cpp Operator.h functions.h exceptions.h functions.cpp)