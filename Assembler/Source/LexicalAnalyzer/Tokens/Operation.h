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
    private:
        std::string m_Op;
    };
}

