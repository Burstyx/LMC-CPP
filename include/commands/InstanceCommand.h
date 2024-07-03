#pragma once
#include <string>
#include <vector>

#include "Command.h"

class InstanceCommand final : public Command {
    std::vector<std::string> m_aliases;
    std::vector<std::string> m_authorizedOptions;
    std::string m_help = "Manage Minecraft instances.\n"
                         "\n"
                         "Usage: lmc instance [options]\n"
                         "\n"
                         "Options:\n"
                         "  create <name> [-v | --version=\"1.12.2\"] [-l | --loader=\"vanilla\"]  Create a new Minecraft instance.\n"
                         "  remove <name>                                                          Remove a Minecraft instance.\n"
                         "  list                                                                   List all Minecraft instances.\n"
                         "  get <name>                                                             List data about a specific Minecraft instance.";

    /*
     * Create a new Minecraft instance.
     *
     * @param name The name of the instance.
     * @param version The version of Minecraft.
     * @param loader The loader to use with Minecraft.
     * @throws InstanceNotFoundException If there is no instance from the specified name.
     */
    void create(const std::string &name, const std::string &version, const std::string &loader);

    /*
     * Remove a new Minecraft instance.
     *
     * @param name The name of the instance.
     * @throws InstanceNotFoundException If there is no instance from the specified name.
     */
    void remove(const std::string &name);

    /*
     * List all Minecraft instances.
     */
    void list();

    /*
     * List data about a specific Minecraft instance.
     *
     * @param name The name of the instance.
     * @throws InstanceNotFoundException If there is no instance from the specified name.
     */
    void get(const std::string &name);

public:
    InstanceCommand(std::vector<std::string> aliases, std::vector<std::string> authorizedOptions);

    [[nodiscard]] const std::vector<std::string> &getAliases() const override;
    [[nodiscard]] const std::vector<std::string> &getAuthorizedOptions() const override;
    [[nodiscard]] const std::string &getHelp() const override;

    void handler(char *args[]) override;
};
