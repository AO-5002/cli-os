cmake_minimum_required(VERSION 4.0)
project(cli_os C)

set(CMAKE_C_STANDARD 17)

add_executable(myshell myshell.c)
add_executable(test test.c)
add_executable(pd pd.c)