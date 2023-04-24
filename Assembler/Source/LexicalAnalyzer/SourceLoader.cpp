#include "SourceLoader.h"

LexicalAnalyzer::SourceLoader::SourceLoader(std::string sourcePath)
    : m_Instructions(0), m_SourcePath("")
{
    m_SourcePath = sourcePath;
}

bool LexicalAnalyzer::SourceLoader::LoadInstructions()
{
    std::ifstream source(m_SourcePath);

    if (!source) {
        printf("[err] couldn't open %s\n", m_SourcePath.c_str());
        return false;
    }

    std::string raw;
    while (std::getline(source, raw)) {
        std::string line = SanitizeLine(raw);

        if (!line.empty() && !IsCommentLine(line)) {
            std::string instruction = CropComment(line);

            m_Instructions.push_back(instruction);
        }
    }

    return true;
}

std::vector<std::string> LexicalAnalyzer::SourceLoader::GetInstructions()
{
    return m_Instructions;
}

std::string LexicalAnalyzer::SourceLoader::SanitizeLine(std::string line)
{
    std::replace(line.begin(), line.end(), '\t', ' ');

    if (line.size() > 0) {
        // remove indenting
        char firstChar = GetFirstChar(line);
        while (firstChar == ' ') {
            line = CropStart(line);
            firstChar = GetFirstChar(line);
        }

        // remove extra tabs and spaces at end of instructions
        char lastChar = GetLastChar(line);
        while(lastChar == ' ') {
            line = CropEnd(line);
            lastChar = GetLastChar(line);
        }
    }

    return line;
}

std::string LexicalAnalyzer::SourceLoader::CropStart(std::string line)
{
    return line.substr(1, line.size());
}

std::string LexicalAnalyzer::SourceLoader::CropEnd(std::string line)
{
    return line.substr(0, line.size() - 1);
}

std::string LexicalAnalyzer::SourceLoader::CropComment(std::string line)
{
    return line.substr(0, line.find("#"));
}

char LexicalAnalyzer::SourceLoader::GetFirstChar(std::string line)
{
    return line[0];
}

char LexicalAnalyzer::SourceLoader::GetLastChar(std::string line)
{
    return line[line.size() - 1];
}

bool LexicalAnalyzer::SourceLoader::IsCommentLine(std::string line)
{
    return line[0] == '#';
}
