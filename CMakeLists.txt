cmake_minimum_required(VERSION 2.6)
set(CMAKE_COLOR_MAKEFILE ON)

# Cesta k modulum CMake
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# TODO: Zde je potreba si jeste pohrat s instalacnima cestama a s vubec vsema cestama :)
set(PROJECT_BINARY_DIR "build/bin" )#CACHE PATH "Installation directory for executables")
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)
