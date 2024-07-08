#pragma once
#include <map>
#include <commands/Command.h>

void commandHandler(const char *command, char *args[], const std::vector<Command*> &commands);
std::string parseArgs(char *args[], const char *shortOption, const char *longOption, const char *defaultValue);