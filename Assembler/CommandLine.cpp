#include "CommandLine.h"

CommandLine::CommandLine(int argc, char* argv[]) {
	std::vector<std::string> vec(argv, argc + argv);
	this->args = vec;

	if (vec.size() > 1) {
		this->filePath = vec[1];
		this->hasFilePath = true;
	}
}

bool CommandLine::HasFilePath() {
	return this->hasFilePath;
}

bool CommandLine::FileExists() {
	struct stat buffer;
	return (stat(this->filePath.c_str(), &buffer) == 0);
}

bool CommandLine::IsValidExtension() {
	std::string suffix = ".asm";

	return this->filePath.size() >= suffix.size() && 0 == this->filePath.compare(
		this->filePath.size() - suffix.size(), suffix.size(), suffix
	);
}