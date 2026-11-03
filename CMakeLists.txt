cmake_minimum_required(VERSION 3.20)
project(GraphDFSBFS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test_data
    src/test_data.cpp
    src/dfs.cpp
)
set(TARGETS test_data)

# bfs is only added once src/bfs.cpp exists
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/bfs.cpp)
    add_executable(bfs src/bfs.cpp src/MatrixGraph.cpp)
    list(APPEND TARGETS bfs)
endif()

foreach(target IN LISTS TARGETS)
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
