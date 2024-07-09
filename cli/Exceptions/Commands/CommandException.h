#pragma once
#include <exception>

namespace LMC {
    class CommandException : public std::exception
    {
    public:
        explicit CommandException(const char* msg);

        [[nodiscard]] const char* what() const noexcept override { return m_Message; }

    private:
        const char* m_Message;
    };
}