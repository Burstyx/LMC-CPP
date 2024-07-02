#pragma once
#include "Command.h"

class InstanceCommand final : public Command
{
    /*
     * Create a new Minecraft instance.
     *
     * @param
     * @throws InstanceNotFoundException If there is no last played instance.
     */
    void create(const std::string& name, const std::string& version, const std::string& loader);

public:
    InstanceCommand() : Command("instance", {"i"}) { }

    void handler(char* args[]) override;
    void help() override;
};
