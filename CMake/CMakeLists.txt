cmake_minimum_required(VERSION 3.6) 
project(foo)

set(FOO_SOURCES some.cpp)
add_library(foos STATIC "${FOO_SOURCES}")

add_executable(foot main.cpp)
target_link_libraries(foot foos)