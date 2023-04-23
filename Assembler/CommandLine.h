#pragma once

#include "vector"
#include "string"

class CommandLine
{
public:
	CommandLine(int argc, char* argv[]);

	bool HasFilePath();
	bool FileExists();
	bool IsValidExtension();
	std::string GetFilePath();

private:
	std::vector<std::string> m_Args;

	bool m_HasFilePath;
	std::string m_FilePath;
};