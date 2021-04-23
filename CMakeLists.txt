cmake_minimum_required(VERSION 3.15)

project(FSM LANGUAGES C)

add_library(fsm_library fsm.c)

add_executable(runner.out runner.c)
target_link_libraries(runner.out PRIVATE fsm_library)
