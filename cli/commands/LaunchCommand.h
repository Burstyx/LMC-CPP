#pragma once
#include <string>
#include <commands/Command.h>

class LaunchCommand final : public Command {
public:
    void handler(char *args[]) override;
    std::string getHelp() override;

protected:
    /**
     * Starts the minecraft instance with the given name.
     *
     * @param instanceName The name of the instance to start.
     * @throws InstanceNotFoundException If the instance with the given name does not exist.
     */
    static void launch(const std::string &instanceName);
};