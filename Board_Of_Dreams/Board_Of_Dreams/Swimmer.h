#pragma once
#include "Entity.h"
class Swimmer: virtual public Entity
{
public:
	Swimmer() = default;
	~Swimmer() override = default;

	bool CanSwim() const override
	{
		return true;
	}
};

