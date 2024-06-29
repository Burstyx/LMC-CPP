cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(LMCCli)

set(SOURCES
        src/LMC.cpp
        src/commands/InstanceCommand.cpp
        src/commands/LaunchCommand.cpp
        src/core/Instance.cpp
        src/handlers/CommandHandler.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)