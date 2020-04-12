#include "Dinosaur.hpp"

Dinosaur::Dinosaur()
	:name(""), gender(Gender::Unknown), period(Period::Unknown), kind(Kind::Unknown), type(Type::Unknown), food(Food::Unknown), cageId(0) {}

Dinosaur::Dinosaur(String _name, Gender _gender, Period _period, Kind _kind, Type _type, Food _food, unsigned int _cageId)
	:name(_name), gender(_gender), period(_period), kind(_kind), type(_type), food(_food), cageId(_cageId) {}

void Dinosaur::loadDinosaur(std::istream& in)
{
	int genderInput = -1, periodInput = -1, kindInput = -1, typeInput = -1, foodInput = -1;
	std::cout << "Name: ";
	in >> this->name;

	DinosaurService::GenderInfo();
	std::cout << "Gender: ";
	in >> genderInput;
	this->gender = DinosaurService::getGenderByIndex(genderInput);

	DinosaurService::PeriodInfo();
	std::cout << "Period: ";
	in >> periodInput;
	this->period = DinosaurService::getPeriodByIndex(periodInput);

	DinosaurService::KindInfo();
	std::cout << "Kind: ";
	in >> kindInput;
	this->kind = DinosaurService::getKindByIndex(kindInput);

	DinosaurService::TypeInfo();
	std::cout << "Type: ";
	in >> typeInput;
	this->type = DinosaurService::getTypeByIndex(typeInput);

	DinosaurService::FoodInfo();
	std::cout << "Food: ";
	in >> foodInput;
	this->food = DinosaurService::getFoodByIndex(foodInput);
}

void Dinosaur::serialize(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		throw std::exception("Cannot open Dinosaurs.bin");
	}

	this->name.serialize(ofs);
	ofs.write((const char*)&this->gender, sizeof(this->gender));
	ofs.write((const char*)&this->period, sizeof(this->period));
	ofs.write((const char*)&this->kind, sizeof(this->kind));
	ofs.write((const char*)&this->type, sizeof(this->type));
	ofs.write((const char*)&this->food, sizeof(this->food));
	ofs.write((const char*)&this->cageId, sizeof(this->cageId));
}

void Dinosaur::printDinosaur()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Gender: " << DinosaurService::printGender(this->gender) << std::endl;
	std::cout << "Period: " << DinosaurService::printPeriod(this->period) << std::endl;
	std::cout << "Kind: " << DinosaurService::printKind(this->kind) << std::endl;
	std::cout << "Type: " << DinosaurService::printType(this->type) << std::endl;
	std::cout << "Food: " << DinosaurService::printFood(this->food) << std::endl;
}

bool operator!=(const Dinosaur& left, const Dinosaur& right)
{
	return !(&left == &right);
}
