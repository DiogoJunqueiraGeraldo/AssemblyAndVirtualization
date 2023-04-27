#pragma once

#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Tokens/Operation.h"
#include "Tokens/Register.h"
#include "Tokens/Label.h"
#include "Tokens/IntegerLiteral.h"
#include "Tokens/Section.h"
#include "Tokens/Token.h"
#include "Tokens/Syscall.h"

namespace LexicalAnalyzer {
	class Tokenizer
	{
	public:
		Tokenizer(std::string sourcePath) : m_SourcePath(sourcePath) {};
		std::vector<Tokens::Token*> Tokenize();

	private:
		void LoadFile();
		void HandleWhiteSpacesAndComments();
		void LoadTokens();

		bool IsMultipleOperandInstruction(std::string instruction);
		void HandleSingleOperand(std::string instruction);
		void HandleMultiOperand(std::string instruction);

	private:
		std::vector<Tokens::Token*> m_Tokens;
		std::vector<std::string> m_Lines;
		std::vector<std::string> m_Instructions;
		std::string m_SourcePath;
	};
}
