#pragma once

#include <string>

#include "CommandBase.h"

namespace LMC {
    class InstanceCommand final : public CommandBase {
    public:
        void Handler(char* args[]) override;
        std::string GetHelp() override;

    protected:
        /**
          * Create a new Minecraft instance.
          *
          * @param name The name of the instance.
          * @param version The version of Minecraft.
          * @param loader The loader to use with Minecraft.
          * @throws InstanceNotFoundException If there is no instance from the specified name.
          */
        static void Create(const std::string& name, const std::string& version, const std::string& loader);

        /**
         * Remove a new Minecraft instance.
         *
         * @param name The name of the instance.
         * @throws InstanceNotFoundException If there is no instance from the specified name.
         */
        static void Remove(const std::string& name);

        /**
         * List all Minecraft instances.
         */
        static void List();

        /**
         * List data about a specific Minecraft instance.
         *
         * @param name The name of the instance.
         * @throws InstanceNotFoundException If there is no instance from the specified name.
         */
        static void Get(const std::string& name);
    };
}
