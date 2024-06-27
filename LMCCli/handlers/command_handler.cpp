#include "command_handler.h"

#include "../commands/launch_command.h"
#include "../exceptions/commands/command_not_found_exception.h"

void command_handler(const char* command, char* args[])
{
    switch (command)
    {
        case "launch":
            launch_command_handler(args);
        default:
            throw command_not_found_exception("Cannot find command " + command);
    }
}
