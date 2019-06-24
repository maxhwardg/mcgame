cmake_minimum_required(VERSION 3.14)
project(mcgame)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

file(GLOB SRC_FILES src/*.cpp include/*.h)

add_library(gamestate STATIC ${SRC_FILES})

if(MSVC)
    target_compile_options(gamestate PRIVATE /W4 /WX)
else()
    target_compile_options(gamestate PRIVATE -Wall -Wextra -pedantic)
endif()
