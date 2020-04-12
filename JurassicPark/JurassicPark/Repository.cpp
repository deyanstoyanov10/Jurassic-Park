#include "Repository.hpp"

unsigned int Repository::allCagesCount = 0;
unsigned int Repository::allDinosaursCount = 0;

Vector<Vector<Cage>> Repository::loadAllCages()
{
	std::ifstream ifs(CagesPath, std::ios::in | std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::exception("File is not open");
	}
	int count = 0;
	ifs.read((char*)&count, sizeof(count));
	ifs.close();

	if (count == 0)
	{
		buildRandomCages();
	}
	
	Vector<Cage> allCages = deserializeAllCages();
	allCagesCount = allCages.count();
	Vector<Dinosaur> allDinosaurs = deserializeAllDinosaurs();
	allDinosaursCount = allDinosaurs.count();
	Vector<Vector<Cage>> zoo = filterCages(allCages, allDinosaurs);

	return zoo;
}

void Repository::serializeAll(Vector<Vector<Cage>> all)
{
	std::ofstream ofs(CagesPath, std::ios::out | std::ios::binary);
	std::ofstream ofsDinosaur(DinosaursPath, std::ios::out | std::ios::binary);

	for (unsigned int i = 0; i < all.count(); i++)
	{
		for (unsigned int j = 0; j < all[i].count(); j++)
		{
			all[i][j].serialize(ofs, ofsDinosaur);
		}
	}

	ofs.close();
	ofsDinosaur.close();
}

Vector<Vector<Cage>> Repository::filterCages(Vector<Cage> cages, Vector<Dinosaur> dinosaurs)
{
	Vector<Vector<Cage>> filteredCages;

	Vector<Cage> terrestrialCages;
	Vector<Cage> airCages;
	Vector<Cage> waterCages;

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		for (unsigned int j = 0; j < dinosaurs.count(); j++)
		{
			if (cages[i].getId() == dinosaurs[j].getCageId())
			{
				cages[i].addDinosaur(dinosaurs[j]);
			}
		}
	}

	for (unsigned int i = 0; i < cages.count(); i++)
	{
		if (cages[i].getClimate() == Climate::Terrestrial)
		{
			terrestrialCages.push_back(cages[i]);
		}
		else if (cages[i].getClimate() == Climate::Air)
		{
			airCages.push_back(cages[i]);
		}
		else if (cages[i].getClimate() == Climate::Water)
		{
			waterCages.push_back(cages[i]);
		}
	}

	filteredCages.push_back(terrestrialCages);
	filteredCages.push_back(airCages);
	filteredCages.push_back(waterCages);

	return filteredCages;
}

Cage Repository::deserializeCage(std::ifstream& ifs)
{
	CageDTO cageDto = CageDTO();

	ifs.read((char*)&cageDto.id, sizeof(cageDto.id));
	ifs.read((char*)&cageDto.size, sizeof(cageDto.size));
	ifs.read((char*)&cageDto.climate, sizeof(cageDto.climate));
	ifs.read((char*)&cageDto.period, sizeof(cageDto.period));

	Cage cage = Cage(cageDto.id, cageDto.size, cageDto.climate, cageDto.period);
	return cage;
}

Vector<Cage> Repository::deserializeAllCages()
{
	std::ifstream ifs(CagesPath, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::exception("File is not open");
	}

	int countCages = 0;
	ifs.read((char*)&countCages, sizeof(countCages));

	Vector<Cage> allCages;
	for (int i = 0; i < countCages; i++)
	{
		allCages.push_back(deserializeCage(ifs));
	}

	ifs.close();
	return allCages;
}

Dinosaur Repository::deserializeDinosaur(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		throw std::exception("Cannot open Dinosaurs.bin");
	}

	DinosaurDTO dinosaurDto = DinosaurDTO();
	dinosaurDto.name.deserialize(ifs);
	ifs.read((char*)&dinosaurDto.gender, sizeof(dinosaurDto.gender));
	ifs.read((char*)&dinosaurDto.period, sizeof(dinosaurDto.period));
	ifs.read((char*)&dinosaurDto.kind, sizeof(dinosaurDto.kind));
	ifs.read((char*)&dinosaurDto.type, sizeof(dinosaurDto.type));
	ifs.read((char*)&dinosaurDto.food, sizeof(dinosaurDto.food));
	ifs.read((char*)&dinosaurDto.cageId, sizeof(dinosaurDto.cageId));

	Dinosaur dinosaur = Dinosaur(dinosaurDto.name, dinosaurDto.gender, dinosaurDto.period, dinosaurDto.kind, dinosaurDto.type, dinosaurDto.food, dinosaurDto.cageId);
	return dinosaur;
}

Vector<Dinosaur> Repository::deserializeAllDinosaurs()
{
	std::ifstream ifs(DinosaursPath, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::exception("File is not open");
	}

	int countDinosaurs = 0;
	ifs.read((char*)&countDinosaurs, sizeof(countDinosaurs));

	Vector<Dinosaur> allDinsaurs;
	for (int i = 0; i < countDinosaurs; i++)
	{
		allDinsaurs.push_back(deserializeDinosaur(ifs));
	}

	ifs.close();
	return allDinsaurs;
}


int Repository::executeIdQuery(const char* path)
{
	std::fstream ifs(path, std::ios::in | std::ios::binary);

	int id = 0;
	ifs.read((char*)&id, sizeof(int));
	ifs.close();

	std::fstream ofs(path, std::ios::out | std::ios::binary);
	int idOut = id + 1;
	ofs.write((const char*)&idOut, sizeof(int));
	ofs.close();

	return id;
}

int Repository::executeCagesId()
{
	int cagesId = executeIdQuery(CagesIdPath);

	return cagesId;
}

void Repository::buildRandomCages()
{
	std::fstream ofs(CagesPath, std::ios::out | std::ios::binary);

	if (!ofs.is_open())
	{
		throw std::exception("File is not open");
	}

	ofs.write((const char*)&MaxRandomCages, sizeof(MaxRandomCages));

	for (unsigned int i = 0; i < MaxRandomCages / 3; i++)
	{
		CageDTO cageDto = createRandomCageDto(Climate::Terrestrial);

		ofs.write((const char*)&cageDto.id, sizeof(cageDto.id));
		ofs.write((const char*)&cageDto.size, sizeof(cageDto.size));
		ofs.write((const char*)&cageDto.climate, sizeof(cageDto.climate));
		ofs.write((const char*)&cageDto.period, sizeof(cageDto.period));
	}

	for (unsigned int i = 0; i < MaxRandomCages / 3; i++)
	{
		CageDTO cageDto = createRandomCageDto(Climate::Air);

		ofs.write((const char*)&cageDto.id, sizeof(cageDto.id));
		ofs.write((const char*)&cageDto.size, sizeof(cageDto.size));
		ofs.write((const char*)&cageDto.climate, sizeof(cageDto.climate));
		ofs.write((const char*)&cageDto.period, sizeof(cageDto.period));
	}

	for (unsigned int i = 0; i < MaxRandomCages / 3; i++)
	{
		CageDTO cageDto = createRandomCageDto(Climate::Water);

		ofs.write((const char*)&cageDto.id, sizeof(cageDto.id));
		ofs.write((const char*)&cageDto.size, sizeof(cageDto.size));
		ofs.write((const char*)&cageDto.climate, sizeof(cageDto.climate));
		ofs.write((const char*)&cageDto.period, sizeof(cageDto.period));
	}
	
	ofs.close();
}

CageDTO Repository::createRandomCageDto(Climate climate)
{
	int id = executeCagesId();
	int size = CageService::randomNumber(3);
	switch (size)
	{
	case 1: size = 1; break;
	case 2: size = 3; break;
	case 3: size = 10; break;
	default:
		break;
	}
	
	Period period = DinosaurService::getPeriodByIndex(CageService::randomNumber(3) - 1);

	CageDTO cageDto = CageDTO(id, size, climate, period);

	return cageDto;
}
