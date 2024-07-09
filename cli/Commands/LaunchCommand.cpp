#include "Commands/LaunchCommand.h"

#include <iostream>

namespace LMC {
    void LaunchCommand::Handler(char* args[]) {
    }

    std::string LaunchCommand::GetHelp() {
        return "Launch a Minecraft instance.";
    }


    void LaunchCommand::Launch(const std::string& instanceName) {
        std::cout << "start mc " << instanceName << '\n';
    }
}