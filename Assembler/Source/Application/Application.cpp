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
	auto shouldExit = !m_ArgumentsHandler->VerifyArguments();
	if (shouldExit) {
		exit(EXIT_FAILURE);
	}

	auto sl = LexicalAnalyzer::SourceLoader(m_ArgumentsHandler->GetFilePath());

	if (!sl.LoadInstructions()) {
		exit(EXIT_FAILURE);
	}

	auto instructions = sl.GetInstructions();

	return;
}
