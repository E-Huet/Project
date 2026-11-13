#pragma once
#include "Map.h"
#include <vector>
#include <string>
#include <fstream>

class LevelParser
{
	std::string pathMap1 = "map0.txt";
	std::string pathMap2 = "map1.txt";
	std::string pathMap3 = "map2.txt";

public :
	std::string GetPathMap1();
	std::string GetPathMap2();
	std::string GetPathMap3();

	bool GetFromFile(std::string path, Map& map);
};