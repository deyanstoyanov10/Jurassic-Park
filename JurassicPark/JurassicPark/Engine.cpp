#include "Engine.hpp"

void Engine::Run()
{
	ConsoleHelper consoleHelper = ConsoleHelper();
	consoleHelper.RenderConsole();

	while (true)
	{
		try
		{
			consoleHelper.ReadCommands();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
