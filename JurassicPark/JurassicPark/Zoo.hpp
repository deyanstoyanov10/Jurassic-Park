#ifndef __ZOO_HPP
#define __ZOO_HPP

#include "Cage.hpp"
#include "Repository.hpp"

class Zoo
{
public:
	Zoo();
	void addDinosaur(Dinosaur dinosaur);
	void removeDinosaur(String name);
	void printZoo();
private:
	Vector<Vector<Cage>> cages;
};

#endif