
#include <iostream>

#include "exceptions/commands/command_exception.h"
#include "handlers/command_handler.h"

int main(int argc, char* argv[])
{
    try { command_handler(argv[1], argv + 2); }
    catch (const command_exception& e) { std::cout << e.what() << '\n'; }
}
