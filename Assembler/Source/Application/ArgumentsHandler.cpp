#include "ArgumentsHandler.h"

Assembler::ArgumentsHandler::ArgumentsHandler(int argc, char* argv[])
    : m_SourcePath(""), m_TargetPath("./"), m_Args(argv, argc + argv)
{
	switch (m_Args.size()) {
		case 3: {
			std::string targetPath = m_Args[2];
			m_TargetPath = targetPath;
		}
		case 2: {
			std::string filePath = m_Args[1];
			m_SourcePath = filePath;
		}
	}
}

std::string Assembler::ArgumentsHandler::GetSourcePath()
{
	if (!HasFilePath()) {
		puts("[err] first argument (target file) is required");
		exit(EXIT_FAILURE);
	}

	if (!FileExists()) {
		puts("[err] first argument should be a (valid) file path");
		exit(EXIT_FAILURE);
	}

	if (!IsValidExtension()) {
		puts("[err] first argument should be a assembly (.asm) file");
		exit(EXIT_FAILURE);
	}

	return m_SourcePath;
}

bool Assembler::ArgumentsHandler::HasFilePath()
{
	return !m_SourcePath.empty();
}

bool Assembler::ArgumentsHandler::FileExists()
{
	struct stat buffer;

	// returns 0 when stat() was successful. The information is returned in buf.
	return !stat(m_SourcePath.c_str(), &buffer);
}

bool Assembler::ArgumentsHandler::IsValidExtension()
{
	std::string extension = ".asm";

	return m_SourcePath.size() >= extension.size() && 0 == m_SourcePath.compare(
		m_SourcePath.size() - extension.size(), extension.size(), extension
	);
}
