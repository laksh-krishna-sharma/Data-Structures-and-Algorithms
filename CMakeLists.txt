cmake_minimum_required(VERSION 3.16)

project(DSA CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Warnings + optimizations
add_compile_options(
  -Wall
  -Wextra
  -Wshadow
  -Wconversion
)

# Output all binaries to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Debug sanitizers
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building with sanitizers")
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

# Subdirectories
add_subdirectory(CRUD/array)
add_subdirectory(CRUD/linked_list)
add_subdirectory(CRUD/queue)