#pragma once
#include "command.h"

class launch_command final : public command
{
public:
    launch_command() : command("launch", {"lch", "l"}) { }
    
    void handler(const char* args[]) override;
    void help() override;
};
