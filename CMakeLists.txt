cmake_minimum_required(VERSION "3.9.1")

project(BinarySearchTree)

# Add lib subdirectory (to build our libraries)
add_subdirectory(lib/bst)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

# When using a header-only, thus, INTERFACE library
target_link_libraries(${PROJECT_NAME}
    bst_interface
)
