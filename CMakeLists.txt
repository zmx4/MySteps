cmake_minimum_required(VERSION 3.10)
project(MySteps)

set(CMAKE_CXX_STANDARD 20)
if(WIN32)
    set(CMAKE_EXECUTABLE_SUFFIX ".exe")
endif()
add_executable(MySteps main.cpp)
