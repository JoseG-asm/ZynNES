cmake_minimum_required(VERSION 4.1)
project(ZynNES)

set(CMAKE_CXX_STANDARD 26)

set(SOURCES
        src/main.cpp
        src/core/nes.cpp
        src/core/nes.h
        src/core/bus.cpp
        src/core/bus.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC src)

