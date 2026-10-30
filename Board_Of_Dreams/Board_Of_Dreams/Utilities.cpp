#include "Utilities.h"
#include "Map.h"

int Coordinates::NbCase(Map map)
{
	return (y* map.GetNbColumns() + x);
}
