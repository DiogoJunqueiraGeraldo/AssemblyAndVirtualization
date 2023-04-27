#pragma once

#include <string>
#include <vector>

namespace Assembler {
	class ArgumentsHandler
	{
	public:
		ArgumentsHandler(int argc, char* argv[]);

		std::string GetSourcePath();
		std::string GetTargetPath() { return m_TargetPath; }

	private:
		bool HasFilePath();
		bool FileExists();
		bool IsValidExtension();

		std::vector<std::string> m_Args;
		std::string m_SourcePath;
		std::string m_TargetPath;
	};
}

