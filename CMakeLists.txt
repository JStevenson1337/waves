## CMake File

cmake_minimum_required(VERSION 3.5)

project(Solar_Sinusoid_Rythym)

# Set the C++ standard
set(CMAKE_C_STANDARD 11)

# Include the directories containing the header files
include_directories(include)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Add the Ncurses library
find_package(findncurses.cmake, ncurses REQUIRED)
include_directories(${NCURSES_INCLUDE_DIRS})

# Add the Wxwidgets library
find_package(wxWidgets REQUIRED)
include(${wxWidgets_INCLUDE_DIRS})

# Add the Math library
find_package(MATH_INCLUDE_DIRS REQUIRED)
include_directories(${MATH_INCLUDE_DIRS})

# Add the JSONCPP library
find_package(JSONCPP REQUIRED)
include_directories(${JSONCPP_INCLUDE_DIRS})

# Add the Vector library
find_package(Vector REQUIRED)
include_directories(${VECTOR_INCLUDE_DIRS})

# Add the executable
add_executable(Solar_Sinusoid_Rythym ${SOURCES})

# Link the libraries
target_link_libraries(Solar_Sinusoid_Rythym 
    ${NCURSES_LIBRARIES}
    ${wxWidgets_LIBRARIES}
    ${MATH_LIBRARIES}
    ${JSONCPP_LIBRARIES}
    ${VECTOR_LIBRARIES}
)

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/obj)
