#pragma once
#include <string>

namespace LMC {
    void CommandHandler(const char* command, char* args[]);
    std::string ParseArgs(char* args[], const char* shortOption, const char* longOption, const char* defaultValue);
}