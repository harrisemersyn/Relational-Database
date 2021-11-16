cmake_minimum_required(VERSION 3.15)
project(databaseproject C)

set(CMAKE_C_STANDARD 99)

add_executable(databaseproject main.c tuple.c tuple.h hashtable.c hashtable.h)