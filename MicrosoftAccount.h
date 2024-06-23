#pragma once
#include <string>

class MicrosoftAccount
{
private:
    std::string m_username_;

public:
    MicrosoftAccount(std::string username) : m_username_(std::move(username)) {}
    std::string get_username() { return m_username_; }
};
