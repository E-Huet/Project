#pragma once
#include <vector>
#include "Utilities.h"
#include "TileInfo.h"

class Map
{
    std::vector<int> map = {};
    SizeMap size;
    std::vector<TileInfo> tiles = {};

    Coordinates coordsPlayer;

    std::vector<Coordinates> ennemies = {};


public : 
    //Getter
    SizeMap GetSizeMap();
    std::vector<int> GetMap();
    bool InLimitsMap(Coordinates coords);
    bool Traversable(Coordinates coords);
    bool Swimmable(Coordinates coords);
    bool Exit(Coordinates coords);
    Coordinates GetCoordsPlayer();
    int InEnnemies(Coordinates coords);

    //Setter
    void AddToMap(int value);
    void AddToEnnemies(Coordinates coords);
    void AddToTiles(TileInfo tileinfo);
    void SetCoordsPlayer(int x, int y);
    void SetSizeMap(int size, int lines, int columns, int enemies);
    void Clear();
    void RemoveEnemy(Coordinates coordsEnnemi);
};