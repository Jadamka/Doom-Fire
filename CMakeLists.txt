cmake_minimum_required(VERSION "3.31.5")

project(DoomFire)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoomFire src/main.cpp)

target_link_libraries(DoomFire PRIVATE -lsfml-graphics -lsfml-system -lsfml-window)
