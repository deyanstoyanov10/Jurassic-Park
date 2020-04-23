#include "InputService.hpp"

InputService::InputService()
{
	this->repo = Repository();
}

void InputService::AddDinosaur()
{
	Dinosaur dinosaur;
	dinosaur.loadDinosaur(std::cin);
	Vector<Cage> cages = this->repo.loadAllCages();

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		if (cages[i].isThisCageSuitable(dinosaur) && cages[i].isAnySpaceInCage() && !repo.checkForExistingName(cages, dinosaur.getName()))
		{
			cages[i].addDinosaur(dinosaur);
			this->repo.serializeAll(cages);
			std::cout << "Dinosaur " << dinosaur.getName() << " successfully added." << std::endl;
			return;
		}
	}

	int size = CageService::randomNumber(3);
	Climate currentClimate = CageService::getClimateByKind(dinosaur.getKind());
	switch (size)
	{
	case 1: size = 1; break;
	case 2: size = 3; break;
	case 3: size = 10; break;
	default: size = 1;
		break;
	}
	
	int newId = this->repo.executeCagesId();
	Cage newCage = Cage(newId ,size, currentClimate, dinosaur.getPeriod());
	
	cages.push_back(newCage);
	cages[cages.count() - 1].addDinosaur(dinosaur);
	this->repo.serializeAll(cages);
	std::cout << "Dinosaur " << dinosaur.getName() << " successfully added." << std::endl;
}

void InputService::RemoveDinosaur(const String& name)
{
	Vector<Cage> cages = this->repo.loadAllCages();
	int index = findCageIdByDinosaurName(cages, name);

	if (index == -1)
	{
		throw std::exception("Dinosaur with this name doesn't exists");
	}

	cages[index].removeDinosaur(name);
	this->repo.serializeAll(cages);

	std::cout << "Dinosaur " << name << " successfully removed." << std::endl;
}

void InputService::printZoo()
{
	Vector<Cage> cages = this->repo.loadAllCages();

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		cages[i].printCage();
	}
}

int InputService::findCageIdByDinosaurName(Vector<Cage> cages, const String& name)
{
	int index = -1;

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		if (cages[i].checkForExistingName(name) == true)
		{
			index = i;
			break;
		}
	}

	return index;
}
