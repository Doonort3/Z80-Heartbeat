cmake_minimum_required(VERSION 3.30)
project(Z80_Heartbeat)

set(CMAKE_C_STANDARD 99)

add_executable(Z80_Heartbeat src/main.c
        include/z80_heartbeat/config.h
        src/cpu.c
        src/cpu.h
        src/memory.c
        src/memory.h
        src/utils.c
        src/utils.h)
