#include <iostream>
#include <string>
#include <ctime>
#include "Grunt.h"

int grunt::attack()
{
	return 5;
}

void grunt::takeDamage(int damage)
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

bool grunt::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}