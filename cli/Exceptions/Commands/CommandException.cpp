#include "Exceptions/Commands/CommandException.h"

namespace LMC {
    CommandException::CommandException(const char *msg): m_Message(msg) {
    }
}