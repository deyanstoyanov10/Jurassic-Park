#include "Cage.hpp"

Cage::Cage()
	:size(0), climate(Climate::Unknown), period(Period::Unknown) {}

Cage::Cage(unsigned int _size, Climate _climate, Period _period)
	:size(_size), climate(_climate), period(_period) {}

void Cage::addDinosaur(Dinosaur dinosaur)
{
	validationForAddingDinosaur(dinosaur);
	initializeCageForFirstAdding(dinosaur);
	this->dinosaurs.push_back(dinosaur);
}

void Cage::removeDinosaur(String name)
{
	int index = 0;
	for (unsigned int i = 0; i < dinosaurs.count(); i++)
	{
		if (dinosaurs[i].getName() == name)
		{
			index = i;
			break;
		}
	}

	this->dinosaurs.deleteAt(index);
}

bool Cage::isAnySpaceInCage()
{
	if (this->dinosaurs.count() < size)
	{
		return true;
	}

	return false;
}

bool Cage::isDinosaurMatch(Dinosaur dinosaur)
{
	if (period != dinosaur.getPeriod() && dinosaurs.count() > 0)
	{
		return false;
	}

	if (dinosaurs[0].getKind() != dinosaur.getKind() && dinosaurs.count() > 0)
	{
		return false;
	}

	return true;
}

bool Cage::checkDinosaurHasName(String name)
{
	for (auto dinosaur : dinosaurs)
	{
		if (dinosaur.getName() == name)
		{
			return true;
		}
	}

	return false;
}

void Cage::validationForAddingDinosaur(Dinosaur dinosaur)
{
	if (this->dinosaurs.count() >= size)
	{
		throw std::exception("This cage is full.");
	}

	if (period != dinosaur.getPeriod() && dinosaurs.count() > 0)
	{
		throw std::exception("Dinosaur doesn't match cage period.");
	}

	if (dinosaurs[0].getKind() != dinosaur.getKind() && dinosaurs.count() > 0)
	{
		throw std::exception("Dinosaur doesn't match kind.");
	}
}

void Cage::initializeCageForFirstAdding(Dinosaur dinosaur)
{
	if (dinosaurs.count() == 0)
	{
		Climate setClimate = CageService::getClimateByKind(dinosaur.getKind());
		this->climate = setClimate;
		this->period = dinosaur.getPeriod();
	}
}
