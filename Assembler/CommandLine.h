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

private:
	std::vector<std::string> args;

	bool hasFilePath;
	std::string filePath;
};