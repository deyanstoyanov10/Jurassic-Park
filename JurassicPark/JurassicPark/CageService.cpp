#include "CageService.hpp"

Cage CageService::createNewCage(Climate climate, Period period)
{
	int size = randomNumber(3);

	if (size == 2)
	{
		size = 3;
	}
	else if (size == 3)
	{
		size = 10;
	}
	else
	{
		size = 1;
	}

	return Cage(size, climate, period);
}

Climate CageService::getClimateByKind(Kind kind)
{
	switch (kind)
	{
	case Kind::Carnivorous: return Climate::Terrestrial;
	case Kind::Herbivorous: return Climate::Terrestrial;
	case Kind::Aquatic: return Climate::Water;
	case Kind::Flying: return Climate::Air;
	default: throw std::exception("Dinosaur doesn't match cage climate.");
		break;
	}
}

int CageService::randomNumber(int maxNumber)
{
	srand(NULL);
	int number = rand() % maxNumber + 1;
	return number;
}
