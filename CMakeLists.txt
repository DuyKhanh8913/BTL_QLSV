cmake_minimum_required(VERSION 3.15)

# Project name and C++ standard
project(QLSV VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/Menu.cpp
    src/Student.cpp
    src/DataManager.cpp
    src/Utils.cpp
)

# Create executable
add_executable(QLSV ${SOURCES})

# Optional: Enable warnings (Windows/MSYS2)
if(MSVC)
    target_compile_options(QLSV PRIVATE /W4 /WX)
else()
    target_compile_options(QLSV PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
