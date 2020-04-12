#include "DinosaurService.hpp"

void DinosaurService::ClimateInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Terrestrial" << std::endl;
	std::cout << "1 => Air" << std::endl;
	std::cout << "2 => Water" << std::endl;
	std::cout << std::endl;
}

void DinosaurService::FoodInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Grass" << std::endl;
	std::cout << "1 => Meat" << std::endl;
	std::cout << "2 => Fish" << std::endl;
	std::cout << std::endl;
}

void DinosaurService::GenderInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Male" << std::endl;
	std::cout << "1 => Female" << std::endl;
	std::cout << std::endl;
}

void DinosaurService::KindInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Carnivorous" << std::endl;
	std::cout << "1 => Herbivorous" << std::endl;
	std::cout << "2 => Aquatic" << std::endl;
	std::cout << "3 => Flying" << std::endl;
	std::cout << std::endl;
}

void DinosaurService::PeriodInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Trias" << std::endl;
	std::cout << "1 => Chalk" << std::endl;
	std::cout << "2 => Jura" << std::endl;
	std::cout << std::endl;
}

void DinosaurService::TypeInfo()
{
	std::cout << std::endl;
	std::cout << "0 => Plesiosaurus" << std::endl;
	std::cout << "1 => Brotosaurus" << std::endl;
	std::cout << "2 => Tyrannosaurus" << std::endl;
	std::cout << std::endl;
}

Climate DinosaurService::getClimateByIndex(int index)
{
	switch (index)
	{
	case 0: return Climate::Terrestrial;
	case 1: return Climate::Air;
	case 2: return Climate::Water;
	default: throw std::exception("Invalid climate input.");
		break;
	}
}

Food DinosaurService::getFoodByIndex(int index)
{
	switch (index)
	{
	case 0: return Food::Grass;
	case 1: return Food::Meat;
	case 2: return Food::Fish;
	default: throw std::exception("Invalid food input.");
		break;
	}
}

Gender DinosaurService::getGenderByIndex(int index)
{
	switch (index)
	{
	case 0: return Gender::Male;
	case 1: return Gender::Female;
	default: throw std::exception("Invalid gender input.");
		break;
	}
}

Kind DinosaurService::getKindByIndex(int index)
{
	switch (index)
	{
	case 0: return Kind::Carnivorous;
	case 1: return Kind::Herbivorous;
	case 2: return Kind::Aquatic;
	case 3: return Kind::Flying;
	default: throw std::exception("Invalid kind input.");
		break;
	}
}

Period DinosaurService::getPeriodByIndex(int index)
{
	switch (index)
	{
	case 0: return Period::Trias;
	case 1: return Period::Chalk;
	case 2: return Period::Jura;
	default: throw std::exception("Invalid period input.");
		break;
	}
}

Type DinosaurService::getTypeByIndex(int index)
{
	switch (index)
	{
	case 0: return Type::Plesiosaurus;
	case 1: return Type::Brotosaurus;
	case 2: return Type::Tyrannosaurus;
	default: throw std::exception("Invalid type input.");
		break;
	}
}

String DinosaurService::printClimate(Climate climate)
{
	String strClimate;

	switch (climate)
	{
	case Climate::Terrestrial: strClimate = "Terrestrial";
		break;
	case Climate::Air: strClimate = "Air";
		break;
	case Climate::Water: strClimate = "Water";
		break;
	default:
		break;
	}

	return strClimate;
}

String DinosaurService::printFood(Food food)
{
	String strFood;

	switch (food)
	{
	case Food::Grass: strFood = "Grass";
		break;
	case Food::Meat: strFood = "Meat";
		break;
	case Food::Fish: strFood = "Fish";
		break;
	default:
		break;
	}

	return strFood;
}

String DinosaurService::printGender(Gender gender)
{
	String strGender;

	switch (gender)
	{
	case Gender::Male: strGender = "Male";
		break;
	case Gender::Female: strGender = "Female";
		break;
	default:
		break;
	}

	return strGender;
}

String DinosaurService::printKind(Kind kind)
{
	String strKind;

	switch (kind)
	{
	case Kind::Carnivorous: strKind = "Carnivorous";
		break;
	case Kind::Herbivorous: strKind = "Herbivorous";
		break;
	case Kind::Aquatic: strKind = "Aquatic";
		break;
	case Kind::Flying: strKind = "Flying";
		break;
	default:
		break;
	}

	return strKind;
}

String DinosaurService::printPeriod(Period period)
{
	String strPeriod;

	switch (period)
	{
	case Period::Trias: strPeriod = "Trias";
		break;
	case Period::Chalk: strPeriod = "Chalk";
		break;
	case Period::Jura: strPeriod = "Jura";
		break;
	default:
		break;
	}

	return strPeriod;
}

String DinosaurService::printType(Type type)
{
	String strType;

	switch (type)
	{
	case Type::Plesiosaurus: strType = "Plesiosaurus";
		break;
	case Type::Brotosaurus: strType = "Brotosaurus";
		break;
	case Type::Tyrannosaurus: strType = "Tyrannosaurus";
		break;
	default:
		break;
	}

	return strType;
}
