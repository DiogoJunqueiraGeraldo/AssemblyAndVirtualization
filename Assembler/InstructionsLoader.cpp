#include "InstructionsLoader.h"

#include <fstream>
#include <algorithm>

bool isEmptyLine(std::string line) {
	return line.size() == 0;
}

bool startsWithAComment(std::string line) {
	return line[0] == '#';
}

std::string sanitizeRawLine(std::string line) {
	if (line.size() > 0 && line[0] == '\t') {
		// remove indenting
		char firstChar = line[0];
		if (firstChar == '\t' || firstChar == ' ') {
			return sanitizeRawLine(line.substr(1, line.size()));
		}

		// remove extra tabs and spaces at end of instructions
		char lastChar = line[line.size() - 1];
		if (lastChar == '\t' || lastChar == ' ') {
			return sanitizeRawLine(line.substr(0, line.size() - 1));
		}
	}

	std::replace(line.begin(), line.end(), '\t', ' ');

	return line;
}

std::vector<std::string> InstructionsLoader::GetRawInstructions() {
	return m_RawInstructions;
}

void InstructionsLoader::LoadInstructions() {
	std::ifstream source(m_FilePath);

	if (!source) {
		printf("(error) couldn't open %s\n", m_FilePath.c_str());
		exit(-1);
	}

	std::string rawLine;
	while (std::getline(source, rawLine)) {
		std::string line = sanitizeRawLine(rawLine);

		if (!isEmptyLine(line) && !startsWithAComment(line)) {
			std::string instruction = line.substr(0, line.find("#"));

			m_RawInstructions.push_back(instruction);
		}
	}
}

InstructionsLoader::InstructionsLoader(std::string filePath) {
	m_FilePath = filePath;
}