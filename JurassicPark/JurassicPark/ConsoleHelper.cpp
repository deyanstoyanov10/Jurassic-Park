#include "ConsoleHelper.hpp"

ConsoleHelper::ConsoleHelper()
{
    this->inputService = new InputService();
}

ConsoleHelper::~ConsoleHelper()
{
    delete inputService;
}

void ConsoleHelper::ReadCommands(Zoo& zoo)
{
    char input[BUFFER];
    std::cin.getline(input, BUFFER);
    InitializeCommand(input, zoo);
}

void ConsoleHelper::RenderConsole()
{
    std::cout << "//===== Welcome to Ivan's Zoo =====//" << std::endl;
    std::cout << "Type help for more information" << std::endl;
}

void ConsoleHelper::RenderHelp()
{
    std::cout << "//===== Information =====//" << std::endl;
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "add dinosaur => Adding new dinosaur" << std::endl;
    std::cout << "add food => Adding food to storage" << std::endl;
    std::cout << "remove dinosaur <name> => Removing dinosaur by name." << std::endl;
    std::cout << "exit => Exiting the program." << std::endl;
}

void ConsoleHelper::InitializeCommand(const char* input, Zoo& zoo)
{
    char** commands;
    int count = ExtractWords(input, commands);

    if (strcmp(commands[0], "add") == 0 && strcmp(commands[1], "dinosaur") == 0)
    {
        this->inputService->AddDinosaur(zoo);
    }
    else if (strcmp(commands[0], "remove") == 0 && strcmp(commands[1], "dinosaur") == 0)
    {
        this->inputService->RemoveDinosaur(zoo, commands[2]);
    }
    else if (strcmp(commands[0], "print") == 0)
    {
        zoo.printZoo();
    }
    else if (strcmp(commands[0], "help") == 0)
    {
        RenderHelp();
    }
    else if (strcmp(commands[0], "exit") == 0)
    {
        std::cout << "Exiting the program..." << std::endl;
        exit(0);
    }
    else
    {
        throw std::exception("Invalid command.");
    }

    for (int i = 0; i < count; i++)
        delete[] commands[i];
    delete[] commands;
}

int ConsoleHelper::ExtractWords(const char* input, char**& commands)
{
    int count = WordCount(input);
    commands = new char* [count];

    for (int i = 0; i < count; i++) {

        while (*input && !IsWordLetter(*input))
            ++input;
        if (*input) {
            const char* start = input;
            while (IsWordLetter(*input))
                ++input;

            int len = input - start;
            commands[i] = new char[len + 1];

            for (int pos = 0; pos < len; ++pos)
                commands[i][pos] = start[pos];
            commands[i][len] = '\0';
        }
    }

    return count;
}

int ConsoleHelper::WordCount(const char* text)
{
    int cnt = 0;
    while (*text) {
        while (*text && !IsWordLetter(*text)) {
            ++text;
        }
        if (*text) {
            ++cnt;
        }
        while (IsWordLetter(*text)) {
            ++text;
        }
    }
    return cnt;
}

bool ConsoleHelper::IsWordLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z');
}
