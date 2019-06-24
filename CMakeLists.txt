cmake_minimum_required(VERSION 3.14)
project(mcgame)

set(CMAKE_CXX_STANDARD 17)

add_executable(mcgame main.cpp)

target_link_libraries(mcgame sfml-graphics sfml-window sfml-system)