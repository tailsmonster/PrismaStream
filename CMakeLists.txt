cmake_minimum_required(VERSION 3.10)
project(PrismaStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES 
    main.cpp
    src/*.cpp
    src/Core/*.cpp
)

add_executable( PrismaStream ${SOURCES})

target_include_directories(PrismaStream PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(PrismaStream PRIVATE portaudio)