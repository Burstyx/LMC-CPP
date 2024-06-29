cmake_minimum_required(VERSION 3.28)

project(tomlplusplus)

set(tomlplusplus_SOURCES
        src/toml.cpp
)

add_library(${PROJECT_NAME} ${tomlplusplus_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
