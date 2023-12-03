cmake_minimum_required(VERSION 3.18)

project(ChessNGin
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(NGin.out main.cpp piece.cpp)