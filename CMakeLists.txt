cmake_minimum_required(VERSION 3.22.0)
project(parrotlogger VERSION 1.0 LANGUAGES C CXX)

add_library(parrot STATIC parrot.cpp parrot.h utils.h)

target_include_directories(parrot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

