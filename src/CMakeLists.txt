# bunnysay CMakeList file
# Required Cmake version
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

## bunnysay
add_executable(bunnysay BunnySay.h BunnySay.cpp)

target_compile_features(bunnysay PRIVATE cxx_range_for)
