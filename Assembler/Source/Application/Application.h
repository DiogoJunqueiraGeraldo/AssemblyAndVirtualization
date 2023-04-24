#pragma once

#include <string>
#include <vector>

#include "ArgumentsHandler.h"
#include "../LexicalAnalyzer/SourceLoader.h"

namespace Assembler {
	class Application
	{
	public:
		Application(int argc, char* argv[]);
		~Application();

		void Assemble();

	private:
		ArgumentsHandler* m_ArgumentsHandler;
	};
}

