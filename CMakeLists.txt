cmake_minimum_required(VERSION 3.10)
project(mcgame)

add_subdirectory(gamestate)

set(CMAKE_CXX_STANDARD 17)

add_executable(mcgame main.cpp)

if(MSVC)
    target_compile_options(mcgame PRIVATE /W4 /WX)
else()
    target_compile_options(mcgame PRIVATE -Wall -Wextra -pedantic)
endif()

target_link_libraries(mcgame gamestate sfml-graphics sfml-window sfml-system)