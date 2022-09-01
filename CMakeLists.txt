cmake_minimum_required(VERSION 3.20)
project(Bolt VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

add_library(Bolt SHARED)
target_sources(Bolt PRIVATE Bolt.cpp)

add_subdirectory(Client)
add_subdirectory(Includes)

git_clone(
    PROJECT_NAME                    SDK
    GIT_URL                         https://github.com/OvermindMC/Elpida_SDK
    [GIT_TAG|GIT_BRANCH|GIT_COMMIT  GIT_BRANCH]
    [QUIET]
)

add_subdirectory(${SDK_SOURCE_DIR})
target_include_directories(Bolt PRIVATE "${SDK_SOURCE_DIR}")

target_link_libraries(Bolt PRIVATE minhook SDK)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})