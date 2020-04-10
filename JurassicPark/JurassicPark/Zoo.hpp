#pragma once

#include "Cage.hpp"
#include "CageService.hpp"

class Zoo
{
public:
	void addDinosaur(Dinosaur dinosaur);
	void removeDinosaur(String name);
private:
	Vector<Vector<Cage>> cages;
};