#pragma once
#include <exception>

namespace LMC {
    class InstanceException : public std::exception
    {
    public:
        explicit InstanceException(const char* msg);

        [[nodiscard]] const char* what() const noexcept override { return m_Message; }

    private:
        const char* m_Message;
    };
}