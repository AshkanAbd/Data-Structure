cmake_minimum_required(VERSION 3.4)
project(Data-Structure)

set(CMAKE_CXX_STANDARD 11)

include_directories(SortAlgorithms)
include_directories(LinkedList)

link_directories(SortAlgorithms)
link_directories(LinkedList)

add_subdirectory(SortAlgorithms)
add_subdirectory(LinkedList)

add_executable(Data-Structure main.cpp)

target_link_libraries(Data-Structure SortAlgorithms LinkedList)