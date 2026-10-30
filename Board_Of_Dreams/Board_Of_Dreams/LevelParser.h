#pragma once
#include "Map.h"
#include <vector>
#include <string>
#include <fstream>

static class LevelParser
{
	std::string pathMap1 = "";
	std::string pathMap2 = "";
	std::string pathMap3 = "";

public :
	int GetSize(Map map, std::string path);
	std::vector<int> GetMap(Map map, std::string path);
};