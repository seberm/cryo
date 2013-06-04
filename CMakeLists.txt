cmake_minimum_required(VERSION 2.6)
set(CMAKE_COLOR_MAKEFILE ON)

# Nastavime flagy
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

# Zapneme podporu C++11
# TODO: Jeste overit, ze se C++11 opravdu zapina!
add_definitions("-std=c++0x")

# Cesta k modulum CMake
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Prefix pro instalaci - defaultne u vetsiny distribuci /usr/local
if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif()

# Adresar pro binarni data
if (NOT DEFINED CMAKE_INSTALL_BINARY_DIR)
    set(INSTALL_BINARY_DIR "${CMAKE_INSTALL_PREFIX}/bin")
else ()
    set(INSTALL_BINARY_DIR "${CMAKE_INSTALL_BINARY_DIR}")
endif()

# Adresar pro data programu
if (NOT DEFINED CMAKE_INSTALL_DATA_DIR)
    set(INSTALL_DATA_DIR "${CMAKE_INSTALL_PREFIX}/share")
else()
    set(INSTALL_DATA_DIR "${CMAKE_INSTALL_DATA_DIR}")
endif()

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

set(bitness 32)
if (CMAKE_SIZEOF_VOID_P EQUAL 8) # Jedna se o 64bit architekturu?
    set(bitness 64)
endif()

# Slozka pro knihovny se lisi v zavislosti na architekture
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
if (bitness EQUAL 64)
    set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib64")
endif()

#set(PROJECT_BINARY_DIR "build/bin" )#CACHE PATH "Installation directory for executables")

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(src)
