#include "Repository.hpp"

Vector<Cage> Repository::loadAllCages()
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
	Vector<Dinosaur> allDinosaurs = deserializeAllDinosaurs();

	Vector<Cage> deserializedCages = filterCages(allCages, allDinosaurs);
	
	return deserializedCages;
}

void Repository::serializeAll(Vector<Cage> all)
{
	std::ofstream ofsCages(CagesPath, std::ios::out | std::ios::binary);
	std::ofstream ofsDinosaur(DinosaursPath, std::ios::out | std::ios::binary);

	unsigned int countCages = all.count();
	unsigned int sumAllDinosaurs = 0;
	
	for (unsigned int i = 0; i < countCages; i++)
	{
		sumAllDinosaurs += all[i].getCurrentSizeInCage();
	}

	ofsCages.write((const char*)&countCages, sizeof(countCages));
	ofsDinosaur.write((const char*)&sumAllDinosaurs, sizeof(sumAllDinosaurs));
	
	for (unsigned int i = 0; i < all.count(); i++)
	{
		all[i].serializeAllDinosaurs(ofsDinosaur);
		all[i].serialize(ofsCages);
	}

	ofsCages.close();
	ofsDinosaur.close();
}

Vector<Cage> Repository::filterCages(Vector<Cage> cages, Vector<Dinosaur> dinosaurs)
{
	Vector<Cage> filteredCages = sortCages(cages);

	for (unsigned int i = 0; i < filteredCages.count(); i++)
	{
		for (unsigned int j = 0; j < dinosaurs.count(); j++)
		{
			if (dinosaurs[j].getCageId() - 1 == i)
			{
				filteredCages[i].addDinosaur(dinosaurs[j]);
			}
		}
	}

	return filteredCages;
}

Vector<Cage> Repository::sortCages(Vector<Cage> cages)
{
	Vector<Cage> allCages = cages;

	bool changed = false;

	do
	{
		changed = false;

		for (unsigned int i = 0; i < allCages.count() - 1; i++)
		{
			if (allCages[i].getId() > allCages[i + 1].getId())
			{
				std::swap(allCages[i], allCages[i + 1]);
				changed = true;
			}
		}
	} while (changed);

	return allCages;
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
		Cage cage = Cage();
		cage.deserialize(ifs);
		allCages.push_back(cage);
	}

	ifs.close();
	return allCages;
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
		Dinosaur dinosaur = Dinosaur();
		dinosaur.deserialize(ifs);
		allDinsaurs.push_back(dinosaur);
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

bool Repository::checkForExistingName(Vector<Cage> all, const String& name)
{
	for (unsigned int i = 0; i < all.count(); i++)
	{
		if (all[i].checkForExistingName(name) == true)
		{
			return true;
		}
	}
	return false;
}

void Repository::buildRandomCages()
{
	std::ofstream ofs(CagesPath, std::ios::out | std::ios::binary);

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
		cageDto.storage.serialize(ofs);
	}

	for (unsigned int i = 0; i < MaxRandomCages / 3; i++)
	{
		CageDTO cageDto = createRandomCageDto(Climate::Air);

		ofs.write((const char*)&cageDto.id, sizeof(cageDto.id));
		ofs.write((const char*)&cageDto.size, sizeof(cageDto.size));
		ofs.write((const char*)&cageDto.climate, sizeof(cageDto.climate));
		ofs.write((const char*)&cageDto.period, sizeof(cageDto.period));
		cageDto.storage.serialize(ofs);
	}

	for (unsigned int i = 0; i < MaxRandomCages / 3; i++)
	{
		CageDTO cageDto = createRandomCageDto(Climate::Water);

		ofs.write((const char*)&cageDto.id, sizeof(cageDto.id));
		ofs.write((const char*)&cageDto.size, sizeof(cageDto.size));
		ofs.write((const char*)&cageDto.climate, sizeof(cageDto.climate));
		ofs.write((const char*)&cageDto.period, sizeof(cageDto.period));
		cageDto.storage.serialize(ofs);
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
