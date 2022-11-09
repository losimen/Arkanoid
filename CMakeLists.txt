cmake_minimum_required(VERSION 3.5)

project (Arkanoid)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/cmake-build-debug/libFrameworkRelease.dylib)
file(GLOB LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/cmake-build-debug/libFrameworkRelease.0.0.1.dylib)

link_directories(path_to_lib)
add_executable(${PROJECT_NAME} main.cpp MyFramework.cpp MyFramework.h)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2_image::SDL2_image ${LIBRARIES})
