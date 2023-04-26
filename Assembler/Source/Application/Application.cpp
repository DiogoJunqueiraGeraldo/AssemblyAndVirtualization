#include "Application.h"

Assembler::Application::Application(int argc, char* argv[])
	: m_ArgumentsHandler(0, nullptr)
{
	m_ArgumentsHandler = ArgumentsHandler(argc, argv);
}

void Assembler::Application::Assemble()
{
	m_ArgumentsHandler.VerifyArguments();

	LexicalAnalyzer::Tokenizer tokenizer = LexicalAnalyzer::Tokenizer(
		m_ArgumentsHandler.GetFilePath()
	);

	tokenizer.Tokenize();

	std::vector<Tokens::Token> tokens = tokenizer.GetTokens();

	return;
}
