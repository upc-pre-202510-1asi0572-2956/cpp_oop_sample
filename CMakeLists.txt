# Minimum required CMake version for compatibility
cmake_minimum_required(VERSION 3.30)

# Project name
project(cpp_oop_sample)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Include the directories containing the header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
        main.cpp
        src/Resource.cpp
        src/ConsumableResource.cpp
        src/UsableResource.cpp
        src/Executable.cpp
        src/Task.cpp
        src/Process.cpp)

# Define the executable target
add_executable(cpp_oop_sample ${SOURCES})
