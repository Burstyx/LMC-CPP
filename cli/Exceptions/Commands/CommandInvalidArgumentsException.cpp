#include "Exceptions/Commands/CommandInvalidArgumentsException.h"

namespace LMC {
    CommandInvalidArgumentsException::CommandInvalidArgumentsException(const char* msg) : CommandException(msg) { }
}