
#include <iostream>

#include "handlers/command_handler.h"

int main(int argc, char* argv[])
{
    command_handler(argv[1], argv + 2);
}
