#pragma once

#include "Dinosaur.hpp"
#include "Repository.hpp"

class InputService
{
public:
	InputService();

	void AddDinosaur();
	void RemoveDinosaur(const String& name);
	void printZoo();
private:
	int findCageIdByDinosaurName(Vector<Cage> cages, const String& name);
	Repository repo;
};