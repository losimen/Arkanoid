cmake_minimum_required(VERSION 3.5)

project(Framework VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 11)
set(SOURCES ./src/launch.cpp)
set(CMAKE_BUILD_TYPE Release)
set(MY_LIBNAME Framework${CMAKE_BUILD_TYPE})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

link_directories(${SDL2})

add_library(${MY_LIBNAME} SHARED ./src/launch.cpp)
set_target_properties(${MY_LIBNAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${MY_LIBNAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set_target_properties(${MY_LIBNAME} PROPERTIES PUBLIC_HEADER inc/Framework.h)

target_include_directories(${MY_LIBNAME} PRIVATE .)
target_link_libraries(${MY_LIBNAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)
