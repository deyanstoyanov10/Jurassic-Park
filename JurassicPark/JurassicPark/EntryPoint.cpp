#include "Engine.hpp"

int main()
{
	Engine engine = Engine();
	engine.Run();

	/*Vector<Vector<Cage>> allCages = Repository::loadAllCages();
	allCages[0][0].addDinosaur(Dinosaur("Pesho", Gender::Male, Period::Trias, Kind::Carnivorous, Type::Plesiosaurus, Food::Grass, 1));

	
	for (unsigned int i = 0; i < allCages.count(); i++)
	{
		for (unsigned int j = 0; j < allCages[i].count(); j++)
		{
			allCages[i][j].printCage();
		}
	}*/

	return 0;
}