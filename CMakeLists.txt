cmake_minimum_required(VERSION 3.16)
project(data_structures_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(data_structures_cpp main.cpp
        first_structures_cpp.cpp
        graphs.cpp
        search-graphs.cpp)
add_executable(first_structures_cpp first_structures_cpp.cpp)
add_executable(graphs graphs.cpp)
add_executable(search-graphs search-graphs.cpp)
