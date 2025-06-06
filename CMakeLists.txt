cmake_minimum_required(VERSION 3.10)
project(PrismaStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(PrismaStream 
    main.cpp
    src/Core/Init.cpp
    src/Core/Device.cpp
    src/Core/Stream.cpp
    src/Playback.cpp
)

target_include_directories(PrismaStream PRIVATE include)
target_link_libraries(PrismaStream PRIVATE portaudio)