#pragma once
#include "../Headers.h"

#include "Compiled.h"

struct Command {
	bool isEditable;
	std::vector<Command*> commandTree;
	std::string name;
	std::string command;
	std::string cppCodeEquivalent;
};

class ConsoleCommands {
private:
	std::vector<Command*> baseComands;
	std::deque<Command*> orderedCommands;
	std::string cppCode;
	std::ifstream console;

	void fillCommandsFromFile();
	void linkCommandTree();

public:
	ConsoleCommands();
	ConsoleCommands(std::string inputFilePath);
	~ConsoleCommands();

private:

	Command* copyCommand(Command*);

	void readPseudoCode();
	void createCppCode();
	bool compileCppCode(std::string inputFilePath, std::string outputFilePath);
	bool linkDll();

public:

	void setConsoleStream(std::string inputFilePath);
	std::shared_ptr<Compiled> buildFunction();

};