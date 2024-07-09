#include "commands/LaunchCommand.h"

#include <iostream>

void LaunchCommand::handler(char* args[]) {
}

std::string LaunchCommand::getHelp() {
    return "Launch a Minecraft instance.";
}


void LaunchCommand::launch(const std::string& instanceName) {
    std::cout << "start mc " << instanceName << '\n';
}
