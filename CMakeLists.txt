cmake_minimum_required(VERSION 3.10)
project(PrismaStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(PrismaStream 
    src/main.cpp
    src/pa_init.cpp
)

target_include_directories(PrismaStream PRIVATE include)
target_link_libraries(PrismaStream PRIVATE portaudio)