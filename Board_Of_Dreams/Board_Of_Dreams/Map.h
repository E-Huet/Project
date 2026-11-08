#pragma once
#include <vector>
#include "Utilities.h"
#include "TileInfo.h"

class Map
{
    std::vector<int> map = {};
    std::vector<Coordinates> ennemies = {};
    std::vector<TileInfo> tiles = {};

    TailleMap size;

public : 
    //Getter
    TailleMap GetSizeMap();
    std::vector<int> GetMap();
    bool CheckLimits();
    bool Traversable(Coordinates coords);
    bool Swimmable(Coordinates coords);
    bool Exit(Coordinates coords);

    //Setter
    void AddToMap(int value);
    void AddToEnnemies(Coordinates coords);
    void AddToTiles(TileInfo tileinfo);

    void DisplayMap();
};