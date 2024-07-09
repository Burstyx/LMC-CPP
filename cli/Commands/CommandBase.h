#pragma once
#include <string>

namespace LMC {
    class CommandBase {
    public:
        virtual ~CommandBase() = default;

        virtual void Handler(char* args[]) = 0;
        virtual std::string GetHelp() = 0;
    };
}