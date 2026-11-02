#include "TileInfo.h"

char TileInfo::GetSymbol(int value)
{
    return symbol;
}

bool TileInfo::IsTraversable(int value)
{
    return false;
}

bool TileInfo::IsSwimmable(int value)
{
    return false;
}


