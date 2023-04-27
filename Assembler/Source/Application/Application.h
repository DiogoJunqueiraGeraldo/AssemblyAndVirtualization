#pragma once

#include <string>
#include <vector>

#include "ArgumentsHandler.h"
#include "../LexicalAnalyzer/Tokenizer.h"

namespace Assembler {
	class Application
	{
	public:
		Application(int argc, char* argv[]) : m_ArgumentsHandler(argc, argv) {};

		void Assemble();

	private:
		ArgumentsHandler m_ArgumentsHandler;
	};
}

