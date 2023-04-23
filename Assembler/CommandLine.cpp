#include "CommandLine.h"

CommandLine::CommandLine(int argc, char* argv[]) {
	std::vector<std::string> vec(argv, argc + argv);
	m_Args = vec;

	if (vec.size() > 1) {
		m_FilePath = vec[1];
		m_HasFilePath = true;
	}
}

bool CommandLine::HasFilePath() {
	return m_HasFilePath;
}

bool CommandLine::FileExists() {
	struct stat buffer;
	return (stat(m_FilePath.c_str(), &buffer) == 0);
}

bool CommandLine::IsValidExtension() {
	std::string suffix = ".asm";

	return m_FilePath.size() >= suffix.size() && 0 == m_FilePath.compare(
		m_FilePath.size() - suffix.size(), suffix.size(), suffix
	);
}

std::string CommandLine::GetFilePath() {
	return m_FilePath;
}