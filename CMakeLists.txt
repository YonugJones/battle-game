cmake_minimum_required(VERSION 3.20)
project(BattleGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(battle src/main.cpp)
target_compile_options(battle PRIVATE -Wall -Wextra -pedantic)