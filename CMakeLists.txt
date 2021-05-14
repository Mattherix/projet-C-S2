cmake_minimum_required(VERSION 3.17)
project(rubik C)

set(CMAKE_C_STANDARD 99)

add_executable(rubik src/main.c)
target_compile_options(rubik PRIVATE -Werror -Wall -Wextra)
