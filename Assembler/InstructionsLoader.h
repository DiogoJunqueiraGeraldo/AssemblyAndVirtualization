#pragma once

#include <vector>
#include <string>

class InstructionsLoader
{
public:

	InstructionsLoader(std::string filePath);
	void LoadInstructions();
	std::vector<std::string> GetRawInstructions();

private:
	std::string m_FilePath;
	std::vector<std::string> m_RawInstructions;
};

