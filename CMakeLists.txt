cmake_minimum_required(VERSION 3.20)

project(labmon VERSION 0.1.0 LANGUAGES CXX)

add_executable(labmon main.cpp)

target_compile_features(labmon PRIVATE cxx_std_20)

install(TARGETS labmon RUNTIME DESTINATION bin)