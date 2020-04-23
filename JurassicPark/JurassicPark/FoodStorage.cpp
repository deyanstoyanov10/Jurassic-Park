#include "FoodStorage.hpp"

FoodStorage::FoodStorage()
	:quantityGrass(0), quantityMeat(0), quantityFish(0) {}

void FoodStorage::addGrass(unsigned int quantity)
{
	this->quantityGrass += quantity;
}

void FoodStorage::addMeat(unsigned int quantity)
{
	this->quantityMeat += quantity;
}

void FoodStorage::addFish(unsigned int quantity)
{
	this->quantityFish += quantity;
}

void FoodStorage::removeGrass(unsigned int quantity)
{
	if (quantityGrass - quantity < 0)
	{
		throw std::exception("Cannot remove grass.");
	}
	this->quantityGrass -= quantity;
}

void FoodStorage::removeMeat(unsigned int quantity)
{
	if (quantityMeat - quantity < 0)
	{
		throw std::exception("Cannot remove meat.");
	}
	this->quantityMeat -= quantity;
}

void FoodStorage::removeFish(unsigned int quantity)
{
	if (quantityFish - quantity < 0)
	{
		throw std::exception("Cannot remove fish.");
	}
	this->quantityFish -= quantity;
}

void FoodStorage::serialize(std::ofstream& ofs)
{
	ofs.write((const char*)&quantityGrass, sizeof(quantityGrass));
	ofs.write((const char*)&quantityMeat, sizeof(quantityMeat));
	ofs.write((const char*)&quantityFish, sizeof(quantityFish));
}

void FoodStorage::deserialize(std::ifstream& ifs)
{
	ifs.read((char*)&quantityGrass, sizeof(quantityGrass));
	ifs.read((char*)&quantityMeat, sizeof(quantityMeat));
	ifs.read((char*)&quantityFish, sizeof(quantityFish));
}