#include <iostream>
#include "LevelParser.h"
#include <string>
#include <fstream>
#include "Map.h"

bool LevelParser::GetFromFile(std::string path, Map& map)
{
    map.Clear();
    std::ifstream file(path);
    std::string ligne;
    if (!file) {
        std::cout << "Impossible d'ouvrir le fichier";
        return false;}
    int linesCounter = 0, columnsCounter = 0, ennemiesCounter = 0;
    TileInfo tile;
    while (std::getline(file, ligne))
    {
        columnsCounter = 0;
        for (int i = 0; i < ligne.length(); i++){
            char character = ligne[i];
            int value = 0;
            if (character == 'M') value = 1;
            else if (character == '~') value = 2;
            else if (character == 'E') value = 3;
            else if (character == 'X') {
                ennemiesCounter++;
                Coordinates coords;
                coords.SetXY(i, linesCounter);
                map.AddToEnnemies(coords);}
            else if (character == 'H') map.SetCoordsPlayer(i, linesCounter);
            map.AddToMap(value);
            tile.SetAll(character, (value == 0 || value == 3), (character == '~'));
            map.AddToTiles(tile);
            columnsCounter++;}
        linesCounter++;}
    map.SetSizeMap(columnsCounter * linesCounter, linesCounter, columnsCounter, ennemiesCounter);
    file.close();
    return true;
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