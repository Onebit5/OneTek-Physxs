# Minimum CMake version required
cmake_minimum_required(VERSION 3.5)

# Project name and version
project(OneTechPhyxs VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add executable
add_executable(OneTechPhyxs 
	main.cpp
	src/vector2.cpp
	src/vector3.cpp
	src/matrix3.cpp
	src/matrix4.cpp
	src/transform.cpp
)