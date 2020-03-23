cmake_minimum_required(VERSION 3.10)
project(pcm2array)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pcm2array
        pcm2array.cpp)
