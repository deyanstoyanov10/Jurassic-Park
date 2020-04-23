#pragma once

#include "Dinosaur.hpp"
#include "Repository.hpp"

class InputService
{
public:
	InputService();

	void AddDinosaur();
	void RemoveDinosaur(const String& name);
	void AddFood(unsigned int cageId, Food food, unsigned int quantity);
	void RemoveFood(unsigned int cageId, Food food, unsigned int quantity);
	void printZoo();
private:
	int findCageIdByDinosaurName(Vector<Cage> cages, const String& name);
	int findCageIndexById(Vector<Cage> cages, unsigned int cageId);
	Repository repo;
};