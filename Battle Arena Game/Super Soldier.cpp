#include <iostream>
#include <string>
#include <ctime>
#include "Super Soldier.h"

int superSoldier::attack()
{
	return 10;
}

void superSoldier::takeDamage(int damage)
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

bool superSoldier::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}