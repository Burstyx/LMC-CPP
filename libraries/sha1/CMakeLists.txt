cmake_minimum_required(VERSION 3.28)

project(sha1)

set(sha1_SOURCES
        src/sha1.cpp
)

add_library(${PROJECT_NAME} ${sha1_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
