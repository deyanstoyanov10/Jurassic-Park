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

	if (name.size() > NAME_LENGTH)
	{
		throw std::exception("Name length cannot be more than 20.");
	}

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
	in.ignore();
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

void Dinosaur::deserialize(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		throw std::exception("Cannot open Dinosaurs.bin");
	}
    
	this->name.deserialize(ifs);
	ifs.read((char*)&gender, sizeof(gender));
	ifs.read((char*)&period, sizeof(period));
	ifs.read((char*)&kind, sizeof(kind));
	ifs.read((char*)&type, sizeof(type));
	ifs.read((char*)&food, sizeof(food));
	ifs.read((char*)&cageId, sizeof(cageId));
}

void Dinosaur::printDinosaur()
{
	String printer;

	std::cout << "|" << this->name;
	printer.repeat(" ", NAME_LENGTH - this->name.size());

	String gender = DinosaurService::printGender(this->gender);
	std::cout << "|" << gender;
	printer.repeat(" ", GENDER_LENGTH - gender.size());

	String period = DinosaurService::printPeriod(this->period);
	std::cout << "|" << period;
	printer.repeat(" ", PERIOD_LENGTH - period.size());

	String kind = DinosaurService::printKind(this->kind);
	std::cout << "|" << kind;
	printer.repeat(" ", KIND_LENGTH - kind.size());

	String type = DinosaurService::printType(this->type);
	std::cout << "|" << type;
	printer.repeat(" ", TYPE_LENGTH - type.size());

	String food = DinosaurService::printFood(this->food);
	std::cout << "|" << food;
	printer.repeat(" ", FOOD_LENGTH - food.size());
	std::cout << "|" << std::endl;

	//std::cout << "Name: " << name << std::endl;
	//std::cout << "Gender: " << DinosaurService::printGender(this->gender) << std::endl;
	//std::cout << "Period: " << DinosaurService::printPeriod(this->period) << std::endl;
	//std::cout << "Kind: " << DinosaurService::printKind(this->kind) << std::endl;
	//std::cout << "Type: " << DinosaurService::printType(this->type) << std::endl;
	//std::cout << "Food: " << DinosaurService::printFood(this->food) << std::endl;
}

bool operator!=(const Dinosaur& left, const Dinosaur& right)
{
	return !(&left == &right);
}
