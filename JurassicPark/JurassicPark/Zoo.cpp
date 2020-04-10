#include "Zoo.hpp"

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

	Cage newCage = CageService::createNewCage(currentClimate, dinosaur.getPeriod());
	this->cages[index].push_back(newCage);

	this->cages[index][cages[index].count() - 1].addDinosaur(dinosaur);
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
}