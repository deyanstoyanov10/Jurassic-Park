#pragma once

#include <fstream>
#include "Vector.hpp"
#include "Cage.hpp"
#include "CageDTO.hpp"
#include "DinosaurDTO.hpp"

const int MaxRandomCages = 15;
static const char* CagesPath = "./Database/Cages.bin";
static const char* CagesIdPath = "./Database/CagesId.bin";
static const char* DinosaursPath = "./Database/Dinosaurs.bin";
static const char* DinosaursIdPath = "./Database/DinosaursId.bin";

class Repository
{
public:
	static Vector<Vector<Cage>> loadAllCages();
	static void serializeAll(Vector<Vector<Cage>> all);
	static int executeCagesId();
private:
	static Cage deserializeCage(std::ifstream& ifs);
    static Vector<Cage> deserializeAllCages();
	static Dinosaur deserializeDinosaur(std::ifstream& ifs);
	static Vector<Dinosaur> deserializeAllDinosaurs();
	static Vector<Vector<Cage>> filterCages(Vector<Cage> cages, Vector<Dinosaur> dinosaurs);
	 
	static int executeIdQuery(const char* path);
	static void buildRandomCages();
	static CageDTO createRandomCageDto(Climate climate);

	static unsigned int allCagesCount;
	static unsigned int allDinosaursCount;
};