cmake_minimum_required(VERSION 3.15)
project(students)

set(CMAKE_CXX_STANDARD 14)

add_executable(students main.cpp cmake-build-debug/Student.cpp cmake-build-debug/Student.h cmake-build-debug/CMakeFiles/Grades.cpp cmake-build-debug/CMakeFiles/Grades.h cmake-build-debug/CMakeFiles/Util.cpp cmake-build-debug/CMakeFiles/Util.h)