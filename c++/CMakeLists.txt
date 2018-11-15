cmake_minimum_required(VERSION 3.4)
project(Data-Structure)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(LinkedList)
add_subdirectory(SortAlgorithms)

add_executable(Data-Structure main.cpp)
