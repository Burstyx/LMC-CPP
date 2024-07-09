#include <exceptions/instances/InstanceException.h>

InstanceException::InstanceException(const char *msg) : message_(msg) {
}

const char * InstanceException::what() const noexcept {
    return message_;
}
