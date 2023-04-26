#include "Application.h"

Assembler::Application::Application(int argc, char* argv[])
	: m_ArgumentsHandler(nullptr)
{
	m_ArgumentsHandler = new ArgumentsHandler(argc, argv);
}

Assembler::Application::~Application() {
	delete m_ArgumentsHandler;
}

void Assembler::Application::Assemble()
{
	if (!m_ArgumentsHandler->VerifyArguments()) {
		exit(EXIT_FAILURE);
	}

	std::string sourcePath = m_ArgumentsHandler->GetFilePath();

	auto tokenizer = LexicalAnalyzer::Tokenizer(sourcePath);

	tokenizer.Tokenize();

	auto tokens = tokenizer.GetTokens();

	return;
}
