#ifndef __CAGE_HPP
#define __CAGE_HPP

#include "Vector.hpp"
#include "Climate.hpp"
#include "Dinosaur.hpp"
#include "CageService.hpp"

class Cage
{
public:
	Cage(unsigned int _id = 0, unsigned int _size = 0, Climate _climate = Climate::Unknown, Period _period = Period::Unknown);

	void addDinosaur(Dinosaur dinosaur);
	void removeDinosaur(String name);

	const int getId() { return this->id; }
	Climate getClimate() { return this->climate; }
	const int getCurrentSizeInCage() const { return this->dinosaurs.count(); }

	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);
	void serializeAllDinosaurs(std::ofstream& ofs);

	bool isAnySpaceInCage();
	bool isThisCageSuitable(Dinosaur dinosaur);
	bool checkForExistingName(String name);

	void printCage();
private:
	void validationForAddingDinosaur(Dinosaur dinosaur);
	void initializeCageForFirstAdding(Dinosaur dinosaur);
private:
	unsigned int id;
	unsigned int size;
	Climate climate;
	Period period;
	Vector<Dinosaur> dinosaurs;
};

#endif // !__CAGE__HPP