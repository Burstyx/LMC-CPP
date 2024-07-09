#include "Exceptions/Instances/InstanceNotFoundException.h"

namespace LMC {
    InstanceNotFoundException::InstanceNotFoundException(const char* msg) : InstanceException(msg) {
    }
}
