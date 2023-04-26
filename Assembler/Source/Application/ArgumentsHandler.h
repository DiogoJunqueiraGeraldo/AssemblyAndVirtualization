#pragma once

#include <string>
#include <vector>

namespace Assembler {
	class ArgumentsHandler
	{
	public:
		ArgumentsHandler(int argc, char* argv[]);
		~ArgumentsHandler();

		bool VerifyArguments();

		std::string GetFilePath() { return m_FilePath; }
		std::string GetTargetPath() { return m_TargetPath; }

	private:
		bool HasFilePath();
		bool FileExists();
		bool IsValidExtension();

		std::vector<std::string>* m_Args;
		std::string m_FilePath;
		std::string m_TargetPath;
	};
}

