cmake_minimum_required(VERSION 3.27)
project(Assignment3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment3
        utility.h
        ast.h
        ast.cpp
        tokenizer.h
        tokenizer.cpp
        parser.h
        parser.cpp
        vm.h
        vm.cpp
        testParser.cpp
        testVM.cpp)
