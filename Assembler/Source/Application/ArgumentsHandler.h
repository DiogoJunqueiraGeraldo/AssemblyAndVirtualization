#pragma once

#include <string>
#include <vector>

namespace Assembler {
	class ArgumentsHandler
	{
	public:
		ArgumentsHandler(int argc, char* argv[]);
		bool VerifyArguments();

		std::string GetFilePath();
		std::string GetTargetPath();

	private:
		bool HasFilePath();
		bool FileExists();
		bool IsValidExtension();

		std::vector<std::string> m_Args;
		std::string m_FilePath;
		std::string m_TargetPath;
	};
}

