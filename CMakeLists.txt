cmake_minimum_required(VERSION 3.20)
project(ApplesGame LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ApplesGame 
src/main.cpp
)
