#include <iostream>
#include "LevelParser.h"
#include <string>
#include <fstream>
#include "Map.h"

void LevelParser::GetFromFile(std::string path, Map& map)
{
    std::ifstream fichier(path);
    std::string ligne;
    if (!fichier) {
        std::cout << "Impossible d'ouvrir le fichier";
    }
    int linesCounter = 0;
    int columnsCounter = 0;
    int ennemiesCounter = 0;
    TileInfo tile;

    while (std::getline(fichier, ligne))
    {
        linesCounter++;
        for (int i = 0; i < ligne.length(); i++)
        {
            if (ligne[i] == '.')
            {
                map.AddToMap(0);
                tile.SetAll('.', true, false);
                map.AddToTiles(tile);
            }
            else if (ligne[i] == 'A')
            {
                map.AddToMap(1);
                tile.SetAll('A', false, false);
                map.AddToTiles(tile);
            }
            else if (ligne[i] == '~')
            {
                map.AddToMap(2);
                tile.SetAll('~', false, true);
                map.AddToTiles(tile);
            }
            else if (ligne[i] == 'E')
            {
                map.AddToMap(3);
                tile.SetAll('E', true, false);
                map.AddToTiles(tile);
            }
            if (ligne[i] == 'X')
            {
                map.AddToMap(0);
                tile.SetAll('.', true, false);
                map.AddToTiles(tile);
                ennemiesCounter++;
                Coordinates coords;
                coords.SetXY(i, columnsCounter);
                map.AddToEnnemies(coords);
            }
            columnsCounter++;
        }
    }
    map.GetSizeMap().SetSize(columnsCounter * linesCounter);
    map.GetSizeMap().SetNbColumns(columnsCounter);
    map.GetSizeMap().SetNbLines(linesCounter);
    map.GetSizeMap().SetNbEnnemies(ennemiesCounter);
}

std::string LevelParser::GetPathMap1()
{
	return pathMap1;
}
std::string LevelParser::GetPathMap2()
{
	return pathMap2;
}
std::string LevelParser::GetPathMap3()
{
	return pathMap3;
}