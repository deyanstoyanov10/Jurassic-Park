#pragma once

#include "Climate.hpp"
#include "Period.hpp"
#include "FoodStorage.hpp"

struct CageDTO
{
	CageDTO(unsigned int id = 0, unsigned int size = 0, Climate climate = Climate::Unknown, Period period = Period::Unknown)
		:id(id), size(size), climate(climate), period(period) 
	{
		this->storage = FoodStorage();
	}
	unsigned int id;
	unsigned int size;
	Climate climate;
	Period period;
	FoodStorage storage;
};