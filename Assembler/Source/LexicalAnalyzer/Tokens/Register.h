#pragma once

#include "Token.h"

namespace Tokens {
    class Register :
        public Token
    {
    public:
        Register(int index) : m_Index(index) {}
        int GetIndex() { return m_Index; }

        std::string GetTokenType() override { return "Register"; }
    private:
        int m_Index;
    };
}
