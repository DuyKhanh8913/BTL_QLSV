# QLSV - Student Management System

A simple C++ console application to manage students: add, find, update, and display all students.

## Features

- Add a new student (ID, name, class)
- Find a student by ID
- Update student info (partial updates allowed)
- Delete student info (partial updates allowed)
- Display all students
- Input validation and sanitization
- IDs and class names are automatically uppercase
- Student names are formatted (first letter uppercase)

## Requirements

- C++17 compiler (g++, clang++, or MSVC)
- CMake 3.15 or higher
- Git (optional, for cloning the repo)
- Supported OS: Windows, Linux, macOS

---

## Installation

### Windows

1. **Install MSYS2** (for g++ compiler):
   - Download: [https://www.msys2.org/](https://www.msys2.org/)
   - Update packages:
     ```powershell
     pacman -Syu
     pacman -S mingw-w64-x86_64-gcc
     ```
2. **Install CMake**:
   - Download: [https://cmake.org/download/](https://cmake.org/download/)
   - During installation, select **“Add CMake to the system PATH”**.
3. **Install Git** (optional, for cloning):
   - [https://git-scm.com/download/win](https://git-scm.com/download/win)

### Linux (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install g++ cmake build-essential git
````

### macOS

```bash
brew install gcc cmake git
```

---

## Build Instructions

1. **Clone the repository** (or download and extract it):

```bash
git clone https://github.com/DuyKhanh8913/BTL_QLSV.git
cd BTL_QLSV
```

2. **Create a build directory**:

```bash
mkdir build
cd build
```

3. **Generate build files with CMake**:

```bash
cmake ..
```

4. **Build the project**:

```bash
cmake --build .
```

5. **Run the executable**:

```bash
# Linux/macOS
./QLSV

# Windows
QLSV.exe
```

---

## Usage

* The program presents a menu with options to:

  1. Add a student
  2. Find a student by ID
  3. Update student info
  4. Display all students
  5. Exit
* When adding a student, **all fields are required**.
* When updating a student, **press Enter to keep the existing value** for any field.
* **IDs and class names** are automatically converted to uppercase.
* **Student names** are sanitized (first letter uppercase, no numbers or special characters).
* After each operation, the program asks if you want to go back to the menu or exit.

---

## Notes

* All input is automatically **trimmed** of leading/trailing spaces.
* Student data is saved to the data file specified in the program.
* The program is designed to work in a console/terminal environment.

---

## License

This project is free to use and modify.

