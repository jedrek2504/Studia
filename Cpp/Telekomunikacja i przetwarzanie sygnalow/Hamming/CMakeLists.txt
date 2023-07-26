cmake_minimum_required(VERSION 3.22)
project(tele1)

set(CMAKE_CXX_STANDARD 17)


add_executable(tele1
        program/main.cpp
        library/src/Algorithm.cpp
        library/include/Algorithm.h
        files/input.txt
        files/encoded.txt
        files/output.txt
        library/src/FileController.cpp
        library/include/FileController.h
        )

