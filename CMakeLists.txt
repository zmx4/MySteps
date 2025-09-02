cmake_minimum_required(VERSION 3.10)


project(MySteps)

#set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
#  # This specific value changes as experimental support evolves. See
#  # `Help/dev/experimental.rst` in the CMake source corresponding to
#  # your CMake build for the exact value to use.
#  "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
#
#project(import_std LANGUAGES CXX)

set(CMAKE_CXX_MODULE_STD 1)



set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILECOMMANDS ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

if(WIN32)
    set(CMAKE_EXECUTABLE_SUFFIX ".exe")
endif()

if(MINGW)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=UTF-8 -fexec-charset=GBK")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=GBK")
endif()

if(CMAKE_C_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O3 -march=native")
	#include_directories(C:\\\\Env\\MSYS\\mingw64\\include)
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8 -O3 -march=native")
	#include_directories(C:\\\\Env\\MSYS\\mingw64\\include)
endif()

#add_executable(MySteps main.cpp)
add_executable(Try     test.cpp)
