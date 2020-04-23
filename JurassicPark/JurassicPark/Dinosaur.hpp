#pragma once

#include "DinosaurService.hpp"
#include "String.hpp"
#include "Gender.hpp"
#include "Period.hpp"
#include "Kind.hpp"
#include "Type.hpp"
#include "Food.hpp"

class Dinosaur
{
public:
	Dinosaur();
	Dinosaur(String _name, Gender _gender, Period _period, Kind _kind, Type _type, Food _food, unsigned int _cageId);

	const String getName() const { return this->name; }
	const Period getPeriod() const { return this->period; }
	const Kind getKind() const { return this->kind; }
	const int getCageId() const { return this->cageId; }
	void setCageId(unsigned int cageId) { this->cageId = cageId; }

	void loadDinosaur(std::istream& in);
	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);

	friend bool operator!=(const Dinosaur& left, const Dinosaur& right);

	void printDinosaur();
private:
	String name;
	Gender gender;
	Period period;
	Kind kind;
	Type type;
	Food food;
	unsigned int cageId;
};