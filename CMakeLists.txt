project(WaveySpots)

cmake_minimum_required(VERSION 2.8)
++ src/*.cpp ./include/header.h -lcurses `wx-config --cxxflags` -o WavySunSpot

add_executable(WaveySpots ${CMAKE_SOURCE_DIR}/*.cpp header.h)
add_include_directories($} )

target_link_libraries(WaveySpots ${WX_LIBRARIES}${NCURSES_LIBRARIES})

include_directories(${WX_INCLUDE_DIRS}${NCURSES_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -lncurses")

set(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/obj)
set(CMAKE_INCLUDE_DIR ${CMAKE_INCLUDE_DIR}/include)

++ src/*.cpp ./include/header.h -lcurses `wx-config --cxxflags` -o WavySunSpot
