#pragma once
#include "Token.h"

namespace Tokens {
    class Syscall :
        public Token
    {
    public:
        std::string GetTokenType() override { return "Syscall"; }
    };
}

