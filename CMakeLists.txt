cmake_minimum_required(VERSION 3.2)

project(BinTree)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_executable(main main.cpp "include/bintree.h")