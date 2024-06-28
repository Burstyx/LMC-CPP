#include "launch_command.h"

#include <iostream>

void LaunchCommand::launch()
{
    std::cout << "start mc" << '\n';
}

void LaunchCommand::launch(const std::string& instanceName)
{
    std::cout << "start mc " << instanceName << '\n';
}

void LaunchCommand::handler(char* args[])
{
    if (args[0] == nullptr)
    {
        launch();
    }
    else
    {
        launch(args[0]);
    }
}

void LaunchCommand::help()
{
}
