#include "Engine.hpp"

int main()
{
	Engine engine = Engine();
	engine.Run();

	/*static const char* CagesPath = "./Database/Cages.bin";
	static const char* CagesIdPath = "./Database/CagesId.bin";
	static const char* DinosaursPath = "./Database/Dinosaurs.bin";

	std::fstream ofs1(CagesIdPath, std::ios::out | std::ios::binary);

	int id = 1;
	ofs1.write((const char*)&id, sizeof(int));
	ofs1.close();

	std::fstream ofs2(CagesPath, std::ios::out | std::ios::binary);
	int idOut = 0;
	ofs2.write((const char*)&idOut, sizeof(int));
	ofs2.close();

	std::fstream ofs3(DinosaursPath, std::ios::out | std::ios::binary);
	int tst = 0;
	ofs3.write((const char*)&tst, sizeof(int));
	ofs3.close();*/

	
	return 0;
}