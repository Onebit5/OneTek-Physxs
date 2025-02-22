# Minimum CMake version required
cmake_minimum_required(VERSION 3.5)

# Project name and version
project(OneTechPhyxs VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL, GLFW, and GLEW
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Include directories
include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})
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

# Link Libraries
target_link_libraries(OneTechPhyxs OpenGL::GL glfw GLEW::GLEW)
