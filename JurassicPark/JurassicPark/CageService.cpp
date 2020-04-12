#include "CageService.hpp"

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
	srand(time(NULL));
	int number = rand() % maxNumber + 1;
	return number;
}