cmake_minimum_required(VERSION 3.20)
project(GraphDFSBFS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test_data src/test_data.cpp)

target_include_directories(test_data PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(test_data PRIVATE /W4)
else()
    target_compile_options(test_data PRIVATE -Wall -Wextra -Wpedantic)
endif()
