#include <iostream>
#include <string>
#include <ctime>
#include "Tank.h"

int tank::attack()
{
	return 15;
}

void tank::takeDamage(int damage)
{
	if (armor > 0)
	{
		armor -= damage;
	}
	if (armor < 0)
	{
		health -= damage;
		if (health < 0)
		{
			health = 0;
		}
	}
}

bool tank::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}
