#include <iostream>
#include <vector>
#include <commands/Command.h>
#include <commands/InstanceCommand.h>
#include <commands/LaunchCommand.h>

#include "exceptions/commands/CommandException.h"
#include "handlers/CommandHandler.h"

int main(const int argc, char *argv[]) {
    if(argc < 2) { std::cout << "No command provided\n"; return 1; }

    const std::vector<Command*> &commands = {
        new InstanceCommand(
            { "instance", "inst" },
            { "-v", "--version", "-l", "--loader" }),
        new LaunchCommand()
    };
    
    try { commandHandler(argv[1], argv + 2, commands); }
    catch (const CommandException& e) { std::cout << e.what() << '\n'; }
}
