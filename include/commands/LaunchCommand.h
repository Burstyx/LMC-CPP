#pragma once
#include "Command.h"

class LaunchCommand final : public Command
{
    /*
     * Starts the last played minecraft instance.
     *
     * @throws InstanceNotFoundException If there is no last played instance.
     */
    void launch();

    /*
     * Starts the minecraft instance with the given name.
     *
     * @param instanceName The name of the instance to start.
     * @throws InstanceNotFoundException If the instance with the given name does not exist.
     */
    void launch(const std::string& instanceName);
    
public:
    LaunchCommand() : Command("launch", {"lch", "l"}) { }
    
    void handler(char* args[]) override;

protected:
    void help() override;
};
