#pragma once

#include "Token.h"

namespace Tokens {
    class IntegerLiteral :
        public Token
    {
    public:
        IntegerLiteral(int value) : m_Value(value) {}
        int GetValue() { return m_Value; }
    private:
        int m_Value;
    };
}

