set(CMAKE_C_COMPILER /usr/bin/gcc)

cmake_minimum_required(VERSION 3.17)
project(project-c C)

set(CMAKE_C_STANDARD 99)


add_executable(project-c src/main.c src/main.h)
target_compile_options(project-c PRIVATE -Werror -Wall -Wextra)
