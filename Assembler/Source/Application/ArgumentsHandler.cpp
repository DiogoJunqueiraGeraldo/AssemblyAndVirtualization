#include "ArgumentsHandler.h"

Assembler::ArgumentsHandler::ArgumentsHandler(int argc, char* argv[])
    : m_Args(0), m_FilePath(""), m_TargetPath("./")
{
	std::vector<std::string> vec(argv, argc + argv);

	switch (vec.size()) {
		case 3: {
			m_TargetPath = vec[2];
		}
		case 2: {
			m_FilePath = vec[1];
		}
		default: {
			m_Args = vec;
		}
	}
}

std::string Assembler::ArgumentsHandler::GetFilePath()
{
	return m_FilePath;
}

std::string Assembler::ArgumentsHandler::GetTargetPath()
{
	return m_TargetPath;
}

bool Assembler::ArgumentsHandler::VerifyArguments()
{
	if (!HasFilePath()) {
		puts("[err] first argument (target file) is required");
		return false;
	}

	if (!FileExists()) {
		puts("[err] first argument should be a (valid) file path");
		return false;
	}

	if (!IsValidExtension()) {
		puts("[err] first argument should be a assembly (.asm) file");
		return false;
	}

	return true;
}

bool Assembler::ArgumentsHandler::HasFilePath()
{
	return !m_FilePath.empty();
}

bool Assembler::ArgumentsHandler::FileExists()
{
	struct stat buffer;

	// returns 0 when stat() was successful. The information is returned in buf.
	return !stat(m_FilePath.c_str(), &buffer);
}

bool Assembler::ArgumentsHandler::IsValidExtension()
{
	std::string extension = ".asm";

	return m_FilePath.size() >= extension.size() && 0 == m_FilePath.compare(
		m_FilePath.size() - extension.size(), extension.size(), extension
	);
}
