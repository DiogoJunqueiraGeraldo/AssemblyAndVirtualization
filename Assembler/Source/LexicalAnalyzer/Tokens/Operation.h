#pragma once
#include "Token.h"

#include <string>

namespace Tokens {
    class Operation :
        public Token
    {
    public:
        Operation(std::string op) : m_Op(op) {}
        std::string GetOp() { return m_Op; }

        std::string GetTokenType() override { return "Operation"; }
    private:
        std::string m_Op;
    };
}

