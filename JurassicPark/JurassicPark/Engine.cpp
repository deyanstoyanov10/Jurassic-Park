#include "Engine.hpp"

void Engine::Run()
{
	Zoo zoo = Zoo();

	ConsoleHelper consoleHelper = ConsoleHelper();
	consoleHelper.RenderConsole();

	while (true)
	{
		try
		{
			consoleHelper.ReadCommands(zoo);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
