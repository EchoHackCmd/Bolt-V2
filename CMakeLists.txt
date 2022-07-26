cmake_minimum_required(VERSION 3.20)
project(Bolt VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_library(Bolt SHARED)
target_sources(Bolt PRIVATE Bolt.cpp "Client/Util/Util.cpp" "Client/Util/Util.h")

add_subdirectory(Client)
add_subdirectory(Includes)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})