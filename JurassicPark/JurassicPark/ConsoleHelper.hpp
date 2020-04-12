#pragma once

#include <iostream>
#include <string.h>
#include "Zoo.hpp"
#include "InputService.hpp"

class ConsoleHelper
{
public:
	ConsoleHelper();
	~ConsoleHelper();
	void ReadCommands(Zoo& zoo);
	void RenderConsole();
private:
	void RenderHelp();
private:
	void InitializeCommand(const char* input, Zoo& zoo);
	int ExtractWords(const char* input, char**& commands);
	int WordCount(const char* text);
	bool IsWordLetter(char c);
private:
	InputService* inputService;
};