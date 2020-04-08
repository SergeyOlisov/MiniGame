cmake_minimum_required(VERSION 3.15)
project(minigame)

set(CMAKE_CXX_STANDARD 14)

add_executable(minigame main.cpp Essence.h Player.h Monsters.h)