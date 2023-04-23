#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

#include "CommandLine.h"
#include "InstructionsLoader.h"

int main(int argc, char* argv[]) {
	CommandLine cli = CommandLine(argc, argv);

	if (!cli.HasFilePath()) {
		puts("(error) first argument (target file) is required");
		return EXIT_FAILURE;
	}

	if (!cli.FileExists()) {
		puts("(error) first argument should be a (valid) file path");
		return EXIT_FAILURE;
	}

	if (!cli.IsValidExtension()) {
		puts("(error) first argument should be a assembly (.asm) file");
		return EXIT_FAILURE;
	}

	InstructionsLoader il = InstructionsLoader(cli.GetFilePath());

	il.LoadInstructions();

	std::vector<std::string> instructions = il.GetRawInstructions();

	return EXIT_SUCCESS;
}