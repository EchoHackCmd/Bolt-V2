cmake_minimum_required(VERSION 3.0.0)
project(Bolt VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Bolt SHARED)
target_sources(Bolt PRIVATE Bolt.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})