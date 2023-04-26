#pragma once

#include "Token.h"

namespace Tokens {
    enum AsmSection {
        TEXT,
        GLOBL,
        DATA
    };

    class Section :
        public Token
    {
    public:
        Section(AsmSection section) : m_Section(section) {}
        AsmSection GetSection() { return m_Section; }
    private:
        AsmSection m_Section;
    };
}

