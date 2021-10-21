cmake_minimum_required (VERSION 3.8)
project(calcproj)


add_executable(calcproj main.cpp)
add_library(calcprojLib STATIC calculator.cpp calculator.h)
target_link_libraries(calcproj calcprojLib)
