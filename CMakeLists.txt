cmake_minimum_required(VERSION 4.2)
project(TapeWorm C)

set(CMAKE_C_STANDARD 11)

add_executable(TapeWorm src/main.c
        src/interpreter.c
        src/include/interpreter.h
        src/lexer.c
        src/include/lexer.h
        src/parser.c
        src/include/parser.h
        src/optimizer.c
        src/include/optimizer.h
        src/codegen.c
        src/include/codegen.h)
