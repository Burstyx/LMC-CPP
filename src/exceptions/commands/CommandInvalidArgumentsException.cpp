#include "exceptions/commands/CommandInvalidArgumentsException.h"

CommandInvalidArgumentsException::CommandInvalidArgumentsException(const char *msg) : CommandException(msg) {
}
