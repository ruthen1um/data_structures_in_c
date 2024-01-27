cmake_minimum_required(VERSION 3.27)
project(data_structures_in_c)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(dslib SHARED
    lib/stack.c
    lib/stack.h
    lib/data.h
)

add_executable(stack examples/stack.c)

target_link_libraries(stack dslib)
target_include_directories(stack PRIVATE include)
