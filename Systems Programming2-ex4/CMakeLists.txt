cmake_minimum_required(VERSION 3.21)
project(sysPro4_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(sources)

add_executable(sysPro4_a
        sources/Ambassador.cpp
        sources/Ambassador.hpp
        sources/Assassin.cpp
        sources/Assassin.hpp
        sources/Captain.cpp
        sources/Captain.hpp
        sources/Contessa.cpp
        sources/Contessa.hpp
        sources/Demo.cpp
        sources/Duke.cpp
        sources/Duke.hpp
        sources/Game.cpp
        sources/Game.hpp
        sources/Player.cpp
        sources/Player.hpp
        doctest.h
        StudentTest1.cpp
        StudentTest2.cpp
        StudentTest3.cpp
        Test.cpp
        TestCounter.cpp
        TestRunner.cpp)
