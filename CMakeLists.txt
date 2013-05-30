cmake_minimum_required(VERSION 2.6)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(PROJECT_BINARY_DIR "build/bin" )#CACHE PATH "Installation directory for executables")
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)
