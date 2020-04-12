#include "InputService.hpp"

void InputService::AddDinosaur(Zoo& zoo)
{
	Dinosaur dinosaur;
	dinosaur.loadDinosaur(std::cin);
	zoo.addDinosaur(dinosaur);
}

void InputService::RemoveDinosaur(Zoo& zoo, const char* name)
{
	zoo.removeDinosaur(name);
}