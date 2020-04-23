#include "Cage.hpp"

Cage::Cage(unsigned int _id, unsigned int _size, Climate _climate, Period _period)
	:id(_id), size(_size), climate(_climate), period(_period) {}

void Cage::addDinosaur(Dinosaur dinosaur)
{
	validationForAddingDinosaur(dinosaur);
	initializeCageForFirstAdding(dinosaur);
	dinosaur.setCageId(this->id);
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

void Cage::serialize(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		throw std::exception("Cannot open Cages.bin");
	}
	
	ofs.write((const char*)&id, sizeof(id));
	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)&climate, sizeof(climate));
	ofs.write((const char*)&period, sizeof(period));
}

void Cage::deserialize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		throw std::exception("Cannot open Cages.bin");
	}

	ifs.read((char*)&id, sizeof(id));
	ifs.read((char*)&size, sizeof(size));
	ifs.read((char*)&climate, sizeof(climate));
	ifs.read((char*)&period, sizeof(period));
}

void Cage::serializeAllDinosaurs(std::ofstream& ofs)
{
	for (unsigned int i = 0; i < dinosaurs.count(); i++)
	{
		this->dinosaurs[i].serialize(ofs);
	}
}

bool Cage::isAnySpaceInCage()
{
	if (this->dinosaurs.count() < size)
	{
		return true;
	}

	return false;
}

bool Cage::isThisCageSuitable(Dinosaur dinosaur)
{
	if (period != dinosaur.getPeriod() && dinosaurs.count() > 0)
	{
		
		return false;
	}

	if (dinosaurs.count() > 0)
	{
		if (dinosaurs[0].getKind() != dinosaur.getKind())
		{
			return false;
		}
	}

	return true;
}

bool Cage::checkForExistingName(String name)
{
	for (unsigned int i = 0; i < dinosaurs.count(); i++)
	{
		if (dinosaurs[i].getName() == name)
		{
			return true;
		}
	}

	return false;
}

void Cage::printCage()
{
	std::cout << "Id: " << this->id << std::endl;
	std::cout << "Size: " << this->size << std::endl;
	std::cout << "Climate: " << DinosaurService::printClimate(this->climate) << std::endl;
	std::cout << "Period: " << DinosaurService::printPeriod(this->period) << std::endl;

	for (unsigned int i = 0; i < dinosaurs.count(); i++)
	{
		this->dinosaurs[i].printDinosaur();
	}
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

	if (dinosaurs.count() > 0)
	{
		if (dinosaurs[0].getKind() != dinosaur.getKind())
		{
			throw std::exception("Dinosaur doesn't match kind.");
		}
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
