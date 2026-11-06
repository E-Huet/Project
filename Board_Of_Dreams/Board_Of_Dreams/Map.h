#pragma once
#include <vector>
#include "Utilities.h"

class Map
{
    std::vector<int> map = {};
    TailleMap size;

public : 
    //Getter
    TailleMap GetSizeMap();
    std::vector<int> GetMap();
    bool CheckLimits();
    bool Traversable(Coordinates coords);
    bool Exit(Coordinates coords);

    //Setter
    void AddToMap(int value);
    void AddToEnnemies(Coordinates coords);

    void DisplayMap();
};