#pragma once

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
	Dinosaur(String _name, Gender _gender, Period _period, Kind _kind, Type _type, Food _food);

	const String getName() const { return this->name; }
	const Period getPeriod() const { return this->period; }
	const Kind getKind() const { return this->kind; }
private:
	String name;
	Gender gender;
	Period period;
	Kind kind;
	Type type;
	Food food;
};