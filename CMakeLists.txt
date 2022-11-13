cmake_minimum_required(VERSION 3.5)

project(Arkanoid)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Framework)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/Framework/libFrameworkRelease.dylib)
file(GLOB LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/Framework/libFrameworkRelease.0.0.1.dylib)

include(Objects/CMakeLists.txt)

list(APPEND myApp_INCLUDES ${CMAKE_CURRENT_LIST_DIR}
                           ${CMAKE_CURRENT_LIST_DIR}/Framework/inc)

list(APPEND myApp_SOURCES ${CMAKE_CURRENT_LIST_DIR}/main.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Game.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/Game.h)

add_executable(${PROJECT_NAME} ${myApp_SOURCES})
include_directories(${myApp_INCLUDES})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image ${LIBRARIES})
