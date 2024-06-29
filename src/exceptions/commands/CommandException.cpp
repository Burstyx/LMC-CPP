#include "exceptions/commands/CommandException.h"

CommandException::CommandException(const char *msg): message_(msg) {
}

const char * CommandException::what() const noexcept {
    return message_;
}
