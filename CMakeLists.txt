cmake_minimum_required(VERSION 3.8)
project(Bundestagswahl)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp klassen.h methoden.cpp)
add_executable(Bundestagswahl ${SOURCE_FILES})