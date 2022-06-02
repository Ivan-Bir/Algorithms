cmake_minimum_required(VERSION 3.16)
project(graph_lib)


add_definitions("-g -O0 -std=c++17 -Wall -Wextra -Wpedantic") #-Werror


set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ListGraph.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/MatrixGraph.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ArcGraph.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/SetGraph.cpp)
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include/virtual
                 ${CMAKE_CURRENT_SOURCE_DIR}/include/impl)


message("SOURCES = ${SOURCES}")
message("INCLUDE_DIRS = ${INCLUDE_DIRS}")


add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} )



project(graph)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} )
target_link_libraries(${PROJECT_NAME} PRIVATE graph_lib)


add_subdirectory(tests)
