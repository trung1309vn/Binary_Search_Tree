cmake_minimum_required(VERSION 3.9.1)

project(bst)

# Add INTERFACE library, thus, header-only
add_library(${PROJECT_NAME}_interface INTERFACE)

# Add target include libraries, thus, the header file include path
target_include_directories(${PROJECT_NAME}_interface 
    INTERFACE 
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
)
