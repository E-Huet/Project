#pragma once
#include <vector>
#include "Utilities.h"

class Map
{
    std::vector<int> map = {};

    int size = 0;
    int nb_lines = 0;
    int nb_columns = 0;
    int nb_ennemies = 0;

public : 
    //Getter
    std::vector<int> GetMap();
    int GetSize();
    int GetNbLines();
    int GetNbColumns();
    int GetNbEnnemies();

    //Setter
    void SetMap(std::vector<int> vector);
    void SetSize(int value);
    void SetNbLines(int value);
    void SetNbColumns(int value);
    void SetNbEnnemies(int value);

    //Others
    void DisplayMap();
    bool CheckLimits();
    bool Traversable(Coordinates coords);
    bool Exit(Coordinates coords);
};