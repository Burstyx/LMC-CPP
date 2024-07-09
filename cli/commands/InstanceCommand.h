#pragma once
#include <string>
#include <commands/Command.h>

class InstanceCommand final : public Command {
public:
    void handler(char *args[]) override;
    std::string getHelp() override;

protected:
    /**
      * Create a new Minecraft instance.
      *
      * @param name The name of the instance.
      * @param version The version of Minecraft.
      * @param loader The loader to use with Minecraft.
      * @throws InstanceNotFoundException If there is no instance from the specified name.
      */
    static void create(const std::string &name, const std::string &version, const std::string &loader);

    /**
     * Remove a new Minecraft instance.
     *
     * @param name The name of the instance.
     * @throws InstanceNotFoundException If there is no instance from the specified name.
     */
    static void remove(const std::string &name);

    /**
     * List all Minecraft instances.
     */
    static void list();

    /**
     * List data about a specific Minecraft instance.
     *
     * @param name The name of the instance.
     * @throws InstanceNotFoundException If there is no instance from the specified name.
     */
    static void get(const std::string &name);
};