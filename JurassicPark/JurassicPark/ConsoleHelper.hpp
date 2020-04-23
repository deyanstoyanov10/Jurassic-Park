#pragma once

#include <iostream>
#include <string.h>
#include "InputService.hpp"
#include "String.hpp"

const int BUFF = 100;

class ConsoleHelper
{
public:
	ConsoleHelper();
	void ReadCommands();
	void RenderConsole();
private:
	void RenderHelp();
private:
	void InitializeCommand(Vector<String> commands);
	int ExtractWords(const char* input, char**& commands);
	int WordCount(const char* text);
	bool IsWordLetter(char c);
private:
	InputService inputService;
};