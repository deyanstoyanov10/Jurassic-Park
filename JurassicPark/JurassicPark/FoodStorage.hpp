#pragma once

#include <ostream>
#include<fstream>

class FoodStorage
{
public:
	FoodStorage();

	void addGrass(unsigned int quantity);
	void addMeat(unsigned int quantity);
	void addFish(unsigned int quantity);

	void removeGrass(unsigned int quantity);
	void removeMeat(unsigned int quantity);
	void removeFish(unsigned int quantity);

	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);

	const unsigned int getGrass() const { return this->quantityGrass; }
	const unsigned int getMeat() const { return this->quantityMeat; }
	const unsigned int getFish() const { return this->quantityFish; }
private:
	unsigned int quantityGrass;
	unsigned int quantityMeat;
	unsigned int quantityFish;
};