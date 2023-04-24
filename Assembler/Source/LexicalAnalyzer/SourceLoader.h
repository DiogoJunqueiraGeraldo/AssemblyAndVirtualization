#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

namespace LexicalAnalyzer {
	class SourceLoader
	{
	public:
		SourceLoader(std::string sourcePath);
		bool LoadInstructions();

		std::vector<std::string> GetInstructions();
	private:
		std::string SanitizeLine(std::string line);
		std::string CropStart(std::string line);
		std::string CropEnd(std::string line);
		std::string CropComment(std::string line);

		char GetFirstChar(std::string line);
		char GetLastChar(std::string line);

		bool IsCommentLine(std::string line);

		std::vector<std::string> m_Instructions;
		std::string m_SourcePath;
	};
}


