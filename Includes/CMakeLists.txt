add_subdirectory(minhook)
add_subdirectory(imgui)
add_subdirectory(kiero)

target_include_directories(Bolt PRIVATE "${CMAKE_CURRENT_LIST_DIR}/minhook/include")