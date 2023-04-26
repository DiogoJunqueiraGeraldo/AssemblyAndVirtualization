#include "Tokenizer.h"

void LexicalAnalyzer::Tokenizer::LoadFile()
{
	std::ifstream source(m_SourcePath);

	if (!source) {
		puts("[err] couldn't load source file");
		exit(EXIT_FAILURE);
	}

	std::string line;
	while (std::getline(source, line)) {
		m_Lines.push_back(line);
	}
}

void LexicalAnalyzer::Tokenizer::HandleWhiteSpacesAndComments()
{
	for (int i = 0; i < m_Lines.size(); i++) {
		std::string line = m_Lines[i];
		line = line.substr(0, line.find('#'));

		if (line.size() > 0) {
			// Replace Tabs and commas to spaces
			std::replace(line.begin(), line.end(), '\t', ' ');
			std::replace(line.begin(), line.end(), ',', ' ');
			
			// Handle Left Padding Spaces
			char fc = line[0];
			bool skipLine = false;
			while (fc == ' ') {
				line = line.substr(1, line.size());

				if (line.size() == 0) {
					skipLine = true;
					break;
				}

				fc = line[0];
			}

			if (skipLine) {
				continue;
			}

			// Handle Right Padding Spaces
			char lc = line[line.size() - 1];
			while (lc == ' ') {
				line = line.substr(0, line.size() - 1);

				if (line.size() == 0) {
					skipLine = true;
					break;
				}

				lc = line[line.size() - 1];
			}

			if (skipLine) {
				continue;
			}

			std::string sanitizedLine = "";
			char lastChar = '\0';
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ' ' && lastChar == ' ') {
					continue;
				}

				lastChar = line[i];
				sanitizedLine += line[i];
			}

			if (sanitizedLine.size() > 0) {
				m_Instructions.push_back(sanitizedLine);
			}
		}
	}
}

void LexicalAnalyzer::Tokenizer::LoadTokens()
{
	// Instructions Loop
	for (int i = 0; i < m_Instructions.size(); i++)
	{
		std::string instruction = m_Instructions[i];

		// Tokens Loop
		if (IsMultipleOperandInstruction(instruction))
		{
			HandleMultiOperand(instruction);
		}
		else {
			HandleSingleOperand(instruction);
		}
	}
}

bool LexicalAnalyzer::Tokenizer::IsMultipleOperandInstruction(std::string instruction)
{
	return instruction.find(' ') < instruction.size();
}

void LexicalAnalyzer::Tokenizer::HandleSingleOperand(std::string instruction)
{
	// section
	if (instruction[0] == '.') {
		if (instruction == ".data") {
			m_Tokens.push_back(Tokens::Section(Tokens::DATA));
		}
		else if (instruction == ".text") {
			m_Tokens.push_back(Tokens::Section(Tokens::TEXT));
		}
		else {
			printf("[err] unexpected section declaration %s", instruction.c_str());
			exit(EXIT_FAILURE);
		}
	}
	else if(instruction[instruction.size() - 1] == ':') {
		std::string label = instruction.substr(0, instruction.size() - 1);
		m_Tokens.push_back(Tokens::LabelDeclaration(label));
	}
	else if (instruction == "syscall") {
		m_Tokens.push_back(Tokens::Syscall());
	}
	else {
		printf("[err] unexpected operand %s check for (missing parameters) or (misspelling)", instruction.c_str());
		exit(EXIT_FAILURE);
	}
}

void LexicalAnalyzer::Tokenizer::HandleMultiOperand(std::string instruction)
{
	bool firstOperand = true;
	bool finished = false;
	while (!finished)
	{
		std::string token = instruction.substr(0, instruction.find(' '));
		instruction = instruction.substr(instruction.find(' ') + 1, instruction.size());

		if (instruction == token) {
			finished = true;
		}

		if (firstOperand) {
			if (token[0] == '.' && token == ".globl") {
				m_Tokens.push_back(Tokens::Section(Tokens::GLOBL));
			}
			else {
				m_Tokens.push_back(Tokens::Operation(token));
			}

			firstOperand = false;
		}
		else if (token[0] == '$') {
			int idx = -1;

			std::string matches[32][2] = {
				{ "$0", "$r0" },
				{ "$1", "$at" },
				{ "$2", "$v0" },
				{ "$3", "$v1" },
				{ "$4", "$a0" },
				{ "$5", "$a1" },
				{ "$6", "$a2" },
				{ "$7", "$a3" },
				{ "$8", "$t0" },
				{ "$9", "$t1" },
				{ "$10", "$t2" },
				{ "$11", "$t3" },
				{ "$12", "$t4" },
				{ "$13", "$t5" },
				{ "$14", "$t6" },
				{ "$15", "$t7" },
				{ "$16", "$s0" },
				{ "$17", "$s1" },
				{ "$18", "$s2" },
				{ "$19", "$s3" },
				{ "$20", "$s4" },
				{ "$21", "$s5" },
				{ "$22", "$s6" },
				{ "$23", "$s7" },
				{ "$24", "$t8" },
				{ "$25", "$t9" },
				{ "$26", "$k0" },
				{ "$27", "$k1" },
				{ "$28", "$gp" },
				{ "$29", "$sp" },
				{ "$30", "$fp" },
				{ "$31", "$ra" },
			};

			if (token == "$zero") {
				idx = 0;
			}
			else {
				for (int i = 0; i < 32; i++) {
					std::string fm = matches[i][0];
					std::string sm = matches[i][1];

					if (fm == token || sm == token) {
						idx = i;
						break;
					}
				}
			}

			if (idx != -1) {
				m_Tokens.push_back(Tokens::Register(idx));
			}
			else {
				printf("[err] unexpected register reference %s", token.c_str());
				exit(EXIT_FAILURE);
			}
			
		}
		else {
			bool isIntegerLiteral = true;

			for (int i = 0; i < token.size(); i++) {
				if (!isdigit(token[i])) {
					isIntegerLiteral = false;
					break;
				}
			}

			if (isIntegerLiteral) {
				m_Tokens.push_back(Tokens::IntegerLiteral(std::stoi(token)));
			}
			else {
				m_Tokens.push_back(Tokens::LabelReference(token));
			}
		}
	}
}

void LexicalAnalyzer::Tokenizer::Tokenize()
{
	LoadFile();
	HandleWhiteSpacesAndComments();
	LoadTokens();
}
