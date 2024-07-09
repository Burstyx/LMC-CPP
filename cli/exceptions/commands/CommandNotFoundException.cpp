#include <exceptions/commands/CommandNotFoundException.h>

CommandNotFoundException::CommandNotFoundException(const char *msg) : CommandException(msg) {
}
