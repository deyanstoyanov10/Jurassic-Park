#pragma once

#include "Vector.hpp"
#include "Climate.hpp"
#include "Dinosaur.hpp"
#include "CageService.hpp"

class Cage
{
public:
	Cage();
	Cage(unsigned int _size, Climate _climate = Climate::Unknown, Period _period = Period::Unknown);

	void addDinosaur(Dinosaur dinosaur);
	void removeDinosaur(String name);

	bool isAnySpaceInCage();
	bool isDinosaurMatch(Dinosaur dinosaur);
	bool checkDinosaurHasName(String name);
private:
	void validationForAddingDinosaur(Dinosaur dinosaur);
	void initializeCageForFirstAdding(Dinosaur dinosaur);
private:
	unsigned int size;
	Climate climate;
	Period period;
	Vector<Dinosaur> dinosaurs;
};