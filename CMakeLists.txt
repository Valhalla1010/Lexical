cmake_minimum_required(VERSION 3.27)
project(Labb_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Labb_1 main.cpp
        lexer.cpp
        lexer.h
        expr.cpp
        expr.h)
