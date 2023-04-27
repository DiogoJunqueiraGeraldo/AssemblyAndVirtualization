#include "Application.h"

void Assembler::Application::Assemble()
{
	std::string sourcePath = m_ArgumentsHandler.GetSourcePath();
	LexicalAnalyzer::Tokenizer tokenizer = LexicalAnalyzer::Tokenizer(sourcePath);
	std::vector<Tokens::Token*> tokens = tokenizer.Tokenize();

	return;
}
