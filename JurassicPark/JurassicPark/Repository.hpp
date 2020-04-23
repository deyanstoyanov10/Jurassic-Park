#pragma once

#include <fstream>
#include "Vector.hpp"
#include "Cage.hpp"
#include "CageDTO.hpp"

const int MaxRandomCages = 3;
static const char* CagesPath = "./Database/Cages.bin";
static const char* CagesIdPath = "./Database/CagesId.bin";
static const char* DinosaursPath = "./Database/Dinosaurs.bin";

class Repository
{
public:
	Vector<Cage> loadAllCages();
	void serializeAll(Vector<Cage> all);
	int executeCagesId();
	bool checkForExistingName(Vector<Cage> all, const String& name);
private:
    Vector<Cage> deserializeAllCages();
	Vector<Dinosaur> deserializeAllDinosaurs();
	Vector<Cage> filterCages(Vector<Cage> cages, Vector<Dinosaur> dinosaurs);
	Vector<Cage> sortCages(Vector<Cage> cages);

	int executeIdQuery(const char* path);
	void buildRandomCages();
	CageDTO createRandomCageDto(Climate climate);
};