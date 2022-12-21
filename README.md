
# Solar Sinusoid Rythym
Solar Sinusoid Rythym is a C++ project that uses the libraries Ncurses, Wxwidgets, Math, JSONCPP, and Vector.

## Requirements
* Ncurses
* Wxwidgets
* Math
* JSONCPP
* Vector

## Build Instructions
1. Clone the repository
`git clone https://github.com/username/Solar-Sinusoid-Rythym.git`
2. Make sure all the required libraries are installed
3. Create the build folder 
`mkdir build`
4. Enter the build folder and run CMake
`cd build && cmake ..`
5. Compile the source code
`make`
6. Run the executable
`./SolarSinusoidRythym`

## Additional Notes
* The source files are located in the `./src` directory
* The include files are located in the `./inc` directory
* The object files will be located in the `./obj` directory
* The debug and test files are located in the `./debug/test` directory
i# waves
g++ src/*.cpp ./include/header.h -lcurses `wx-config --cxxflags` -o WavySunSpot
