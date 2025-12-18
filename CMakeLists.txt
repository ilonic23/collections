cmake_minimum_required(VERSION 4.0)
project(collections C)

set(CMAKE_C_STANDARD 11)

add_library(collections STATIC collections.c)

add_executable(collections_test collections_test.c)
target_link_libraries(collections_test PRIVATE collections)