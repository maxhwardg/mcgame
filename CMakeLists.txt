cmake_minimum_required(VERSION 3.10)
project(mcgame)

set(CMAKE_CXX_STANDARD 17)

add_executable(mcgame main.cpp include/tiles.h src/tiles.cpp include/image_library.h src/image_library.cpp include/drawing.h src/drawing.cpp)

include_directories(mcgame include)

if(MSVC)
    target_compile_options(mcgame PRIVATE /W4 /WX)
else()
    target_compile_options(mcgame PRIVATE -Wall -Wextra -pedantic)
endif()

target_link_libraries(mcgame sfml-graphics sfml-window sfml-system)


file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})