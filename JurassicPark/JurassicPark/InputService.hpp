#pragma once

#include "Zoo.hpp"

class InputService
{
public:
	void AddDinosaur(Zoo& zoo);
	void RemoveDinosaur(Zoo& zoo, const char* name);
};