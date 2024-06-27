#include "command_exception.h"

command_exception::command_exception(const char* msg) : message_(msg) { }

char const* command_exception::what() const { return message_; }
