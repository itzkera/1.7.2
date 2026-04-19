cmake_minimum_required(VERSION 3.20)

project(MyProject)

# Add MinHook include directory
include_directories(${CMAKE_SOURCE_DIR})

# Create as SHARED library (DLL) - recommended for this kind of project
add_library(MyProject SHARED dllmain.cpp)

# Include directories
target_include_directories(MyProject PRIVATE
        ${CMAKE_SOURCE_DIR}
)

# Link MinHook
target_link_libraries(MyProject PRIVATE
        ${CMAKE_SOURCE_DIR}/MinHook.lib
)

target_compile_features(MyProject PRIVATE cxx_std_20)

target_compile_definitions(MyProject PRIVATE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
)