#pragma once
#include <string>
#include <vector>

#include "Command.h"

class LaunchCommand final : public Command {
    std::vector<std::string> m_aliases;
    std::vector<std::string> m_authorizedOptions;
    std::string m_help = "Launch a Minecraft instance.";
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
    void launch(const std::string &instanceName);

public:
    [[nodiscard]] const std::vector<std::string> &getAliases() const override;
    [[nodiscard]] const std::vector<std::string> &getAuthorizedOptions() const override;
    [[nodiscard]] const std::string &getHelp() const override;

    void handler(char *args[]) override;
};
