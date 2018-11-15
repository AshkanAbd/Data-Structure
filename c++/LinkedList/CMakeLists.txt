cmake_minimum_required(VERSION 3.4)
project(LinkedList)

set(CMAKE_CXX_STANDARD 11)

set(Files linkedlist.cpp linkedlist.h)

add_library(LinkedList ${Files})
