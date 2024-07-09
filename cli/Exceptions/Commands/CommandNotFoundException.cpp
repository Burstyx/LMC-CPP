#include "Exceptions/Commands/CommandNotFoundException.h"

namespace LMC {
    CommandNotFoundException::CommandNotFoundException(const char* msg) : CommandException(msg) {
    }
}
