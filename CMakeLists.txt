cmake_minimum_required(VERSION 3.17)
project(fdepotx C)

set(CMAKE_C_STANDARD 99)

add_executable(fdepotx main.c cmake-build-debug/fmerge.c fmerge.c)