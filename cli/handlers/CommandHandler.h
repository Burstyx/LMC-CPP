#pragma once
#include <string>

void commandHandler(const char *command, char *args[]);
std::string parseArgs(char *args[], const char *shortOption, const char *longOption, const char *defaultValue);