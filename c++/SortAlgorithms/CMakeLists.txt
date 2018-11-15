cmake_minimum_required(VERSION 3.4)
project(SortAlgorithms)

set(CMAKE_CXX_STANDARD 11)

set(Files algorithms.cpp algorithms.h)

add_library(SortAlgorithms ${Files})
