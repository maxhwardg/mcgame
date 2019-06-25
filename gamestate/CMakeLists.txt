cmake_minimum_required(VERSION 3.10)
project(mcgame)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

set(HDR_FILES include/gamestate.h)
set(SRC_FILES src/gamestate.cpp)

add_library(gamestate STATIC ${HDR_FILES} ${SRC_FILES})

if(MSVC)
    target_compile_options(gamestate PRIVATE /W4 /WX)
else()
    target_compile_options(gamestate PRIVATE -Wall -Wextra -pedantic)
endif()
