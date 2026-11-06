#pragma once
#include "Map.h"
#include <vector>
#include <string>
#include <fstream>

class LevelParser
{
	std::string pathMap1 = "map1.txt";
	std::string pathMap2 = " ";
	std::string pathMap3 = " ";

public :
	std::string GetPathMap1();
	std::string GetPathMap2();
	std::string GetPathMap3();

	void GetFromFile(std::string path, Map& map);
};