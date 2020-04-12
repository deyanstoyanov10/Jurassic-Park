#pragma once

#include "String.hpp"
#include "Gender.hpp"
#include "Period.hpp"
#include "Kind.hpp"
#include "Type.hpp"
#include "Food.hpp"

struct DinosaurDTO
{
	DinosaurDTO(String _name = "", Gender _gender = Gender::Unknown, Period _period = Period::Unknown, Kind _kind = Kind::Unknown, Type _type = Type::Unknown, Food _food = Food::Unknown, unsigned int _cageId = 0)
		:name(_name), gender(_gender), period(_period), kind(_kind), type(_type), food(_food), cageId(_cageId) {}

	String name;
	Gender gender;
	Period period;
	Kind kind;
	Type type;
	Food food;
	unsigned int cageId;
};