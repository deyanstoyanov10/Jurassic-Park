#include "Zoo.hpp"

Zoo::Zoo()
{
	this->cages = Repository::loadAllCages();
}

void Zoo::addDinosaur(Dinosaur dinosaur)
{
	Climate currentClimate = CageService::getClimateByKind(dinosaur.getKind());
	
	int index = static_cast<int>(currentClimate);

	for (unsigned int i = 0; i < cages[index].count(); i++)
	{
		if (cages[index][i].isAnySpaceInCage() == true && cages[index][i].isDinosaurMatch(dinosaur) == true)
		{
			cages[index][i].addDinosaur(dinosaur);
			std::cout << "Dinosaur successfully added." << std::endl;
			return;
		}
	}
	
	int size = CageService::randomNumber(3);

	switch (size)
	{
	case 1: size = 1; break;
	case 2: size = 3; break;
	case 3: size = 10; break;
	default: size = 1;
		break;
	}
	
	int newId = Repository::executeCagesId();
	Cage newCage = Cage(newId ,size, currentClimate, dinosaur.getPeriod());
	
	this->cages[index].push_back(newCage);

	this->cages[index][cages[index].count() - 1].addDinosaur(dinosaur);
	Repository::serializeAll(this->cages);
	std::cout << "Dinosaur successfully added." << std::endl;
}

void Zoo::removeDinosaur(String name)
{
	int indexOne = 0, indexTwo = 0;
	bool check = false;

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		for (unsigned int j = 0; j < cages[i].count(); j++)
		{
			if (cages[i][j].checkDinosaurHasName(name))
			{
				indexOne = i;
				indexTwo = j;
				check = true;
			}
		}
	}

	if (check == false)
	{
		throw std::exception("There is no dinosaur with this name.");
	}

	this->cages[indexOne][indexTwo].removeDinosaur(name);

	Repository::serializeAll(this->cages);
}

void Zoo::printZoo()
{
	for (unsigned int i = 0; i < cages.count(); i++)
	{
		for (unsigned int j = 0; j < cages[i].count(); j++)
		{
			this->cages[i][j].printCage();
		}
	}
}
