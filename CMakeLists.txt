cmake_minimum_required(VERSION 3.20)
project(Bolt VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_library(Bolt SHARED)
target_sources(Bolt PRIVATE Bolt.cpp)

add_subdirectory(Client)
add_subdirectory(Includes)

target_link_libraries(Bolt PRIVATE minhook)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})