cmake_minimum_required(VERSION 3.13)
project(circle)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR})

add_executable(circle main.cpp header.h lib.cpp circle.class/circle.cpp circle.class/circle.h)

target_link_libraries(circle ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARIES} -lmingw32 -lSDL2main -lSDL2)