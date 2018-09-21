#include <iostream>
#include <string>
#include <ctime>
#include "Grunt.h"

int grunt::attack(int i, grunt * team, size_t teamLimit)
{
	int damage = rand() % 11;
	int enemy = rand() % teamLimit[i];
	team[enemy].takeDamage(damage);

	if (i < 0)
	{
		std::cout << "RETALIATION!" << std::endl;
	}
	else
	{
		std::cout << "Grunt " << +i << std::endl;
	}
	std::cout << "Grunt " << +enemy << " took " << damage << " damage!" << std::endl;
}

int grunt::retalliate()
{
	int retDamage;
	
	retDamage = rand() % 11;

	return retDamage;
}

void grunt::takeDamage(int damage)
{
	health -= damage;
		if (health < 0)
		{
			health = 0;
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