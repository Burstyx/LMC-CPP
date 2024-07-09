#pragma once
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace LMC {
    void CommandHandler(const char* command, char* args[]);
    std::unordered_map<std::string, std::optional<std::string>> ParseArgs(char* args[], const std::vector<std::pair<std::string, std::string>>& expectedArgs);
}
