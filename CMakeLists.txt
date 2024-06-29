cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(LMCCli
        VERSION 0.1.0
        DESCRIPTION "LaunchMC CLI Tool for managing Minecraft instances."
        LANGUAGES CXX)

set(SOURCES
        src/LMC.cpp
        src/commands/InstanceCommand.cpp
        src/commands/LaunchCommand.cpp
        src/core/Instance.cpp
        src/handlers/CommandHandler.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)