#pragma once

class Command {
public:
    virtual ~Command() = default;

    virtual void handler(char* args[]) = 0;
    virtual std::string getHelp() = 0;
};