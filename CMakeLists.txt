cmake_minimum_required(VERSION 3.30)
project(Z80_Heartbeat)

set(CMAKE_C_STANDARD 99)

add_executable(Z80_Heartbeat src/main.c
        src/cpu.c
        src/memory.c
        src/utils.c
        include/flags.h
        src/flags.c)

include_directories(/include)
