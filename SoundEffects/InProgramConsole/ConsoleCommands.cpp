#include "ConsoleCommands.h"

void ConsoleCommands::fillCommandsFromFile()
{

}

void ConsoleCommands::linkCommandTree()
{

}

ConsoleCommands::ConsoleCommands()
{
	console = std::ifstream(COMMANDS_FILE);
	fillCommandsFromFile();
	linkCommandTree();
}

ConsoleCommands::ConsoleCommands(std::string inputFilePath)
{
	console = std::ifstream(inputFilePath);
	fillCommandsFromFile();
	linkCommandTree();
}

ConsoleCommands::~ConsoleCommands()
{
	for (Command* command : baseComands)
		delete command;

}

Command* ConsoleCommands::copyCommand(Command* copied)
{
	Command* command = new Command;
	command->isEditable = copied->isEditable;
	command->commandTree = copied->commandTree;
	command->name = copied->name;
	command->command = copied->command;
	command->cppCodeEquivalent = copied->cppCodeEquivalent;
}

void ConsoleCommands::readPseudoCode()
{
	for (std::string line; getline(console, line);)
	{

		line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
		while (!line.empty())
		{
			if (std::regex_match(line, std::regex("\((.*?)\).*")))
			{

			}
		}
	}
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
