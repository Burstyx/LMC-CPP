#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace LMC::CommandHandler {
    void CommandHandler(const char* command, char* args[]);
    bool IsValidArg(const char* arg, const std::vector<std::pair<std::string, std::string>>& expectedArgs);
    std::unordered_map<std::string, std::string> ParseArgs(char* args[], const std::vector<std::pair<std::string, std::string>>& expectedArgs);
    std::string GetValue(const std::pair<std::string, std::string>& expectedKeys, const std::unordered_map<std::string, std::string>& parsedArgs);
    std::string GetValueOrDefault(const std::pair<std::string, std::string>& expectedKeys, const std::unordered_map<std::string, std::string>& parsedArgs, const std::string& defaultValue);
}
