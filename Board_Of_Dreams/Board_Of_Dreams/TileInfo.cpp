#include "TileInfo.h"

char TileInfo::GetSymbol()
{
    return symbol;
}

bool TileInfo::IsTraversable()
{
    return traversable;
}

bool TileInfo::IsSwimmable()
{
    return swimmable;
}

void TileInfo::SetAll(char character, bool boolTraversable, bool boolSwimmable)
{
    symbol = character;
    traversable = boolTraversable;
    swimmable = boolSwimmable;
}


