#pragma once
#include "Commands/CommandBase.h"

#include <string>

namespace LMC {
    class LaunchCommand final : public CommandBase {
    public:
        void Handler(char* args[]) override;
        std::string GetHelp() override;

    protected:
        /**
         * Starts the minecraft instance with the given name.
         *
         * @param instanceName The name of the instance to start.
         * @throws InstanceNotFoundException If the instance with the given name does not exist.
         */
        static void Launch(const std::string& instanceName);
    };
}