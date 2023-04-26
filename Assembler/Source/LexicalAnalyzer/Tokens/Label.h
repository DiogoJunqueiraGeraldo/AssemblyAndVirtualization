#pragma once

#include "Token.h"

#include <string>

namespace Tokens {
    class Label: public Token {
        public:
            Label(std::string name) : m_Name(name) {}
            std::string GetName() { return m_Name; }
        protected:
            std::string m_Name;
    };

    class LabelDeclaration :
        public Label
    {
    public:
        LabelDeclaration(std::string name): Label(name) {}
    };

    class LabelReference : public Label {
    public:
        LabelReference(std::string name) : Label(name) {};
    };
}

