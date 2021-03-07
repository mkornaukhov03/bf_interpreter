cmake_minimum_required(VERSION 3.10)

project(bf_interpreter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -fsanitize=address -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O2")

file(GLOB_RECURSE HEADERS "include/*.h")
file(GLOB_RECURSE HEADERS "third_party/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(bf_interpreter ${HEADERS} ${SOURCES})
add_executable(test ${HEADERS} src/interpreter.cpp test/test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC third_party/ include/)
target_include_directories(test PUBLIC third_party/ include/)
