# QLSV - Student Management System

A simple C++ console application to manage students: add, find, update, and display all students.

## Features

- Add a new student (ID, name, class)
- Find a student by ID
- Update student info (partial updates allowed)
- Display all students
- Input validation and sanitization
- IDs and class names are automatically uppercase
- Student names are formatted (first letter uppercase)

## Requirements

- C++17 compiler (g++, clang++, or MSVC)
- CMake 3.15+
- Windows, Linux, or macOS

## Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build executable
cmake --build .
