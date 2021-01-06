#include "ConsoleCommands.h"

void ConsoleCommands::fillCommandsFromFile()
{

}

void ConsoleCommands::linkCommandTree()
{

}

ConsoleCommands::ConsoleCommands()
{

}

ConsoleCommands::ConsoleCommands(std::string inputFilePath)
{
}

ConsoleCommands::ConsoleCommands(std::ifstream inputFileStream)
{
}

ConsoleCommands::~ConsoleCommands()
{
}

Command* ConsoleCommands::copyCommand(Command*)
{
	return nullptr;
}

void ConsoleCommands::readPseudoCode()
{
}

void ConsoleCommands::createCppCode()
{
}

bool ConsoleCommands::compileCppCode(std::string inputFilePath, std::string outputFilePath)
{
	return false;
}

bool ConsoleCommands::linkDll()
{
	return false;
}

void ConsoleCommands::setConsoleStream(std::string inputFilePath)
{
}

std::shared_ptr<Compiled> ConsoleCommands::buildFunction()
{
	return std::shared_ptr<Compiled>();
}
