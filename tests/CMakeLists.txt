cmake_minimum_required(VERSION 3.16)
project(test_graph)

add_definitions("-g -O0 -std=c++17 -Wall -Wextra -Wpedantic")

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} graph_lib GTest::GTest GTest::Main)
