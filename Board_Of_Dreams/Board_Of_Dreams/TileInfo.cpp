#include "TileInfo.h"

char TileInfo::GetSymbol()
{
    return symbol;
}

bool TileInfo::IsTraversable()
{
    return false;
}

bool TileInfo::IsSwimmable()
{
    return false;
}

void TileInfo::SetAll(char character, bool boolTraversable, bool boolSwimmable)
{
    symbol = character;
    traversable = boolTraversable;
    swimmable = boolSwimmable;
}


