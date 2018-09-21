#include <iostream>
#include <string>
#include <ctime>
#include "Grunt.h"

bool grunt::gruntAlive(grunt *teamArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (teamArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

bool grunt::attack(int i, grunt * team, size_t teamLimit)
{
	int enemy = -1;
	int enemyHealth = 0;

	if (!gruntAlive(team, teamLimit))
	{
		return true;
	}
	int damage = rand() % 11;
	while (gruntAlive(team, teamLimit) && enemyHealth == 0)
	{
		enemy = rand() % teamLimit;
		enemyHealth = team[enemy].health;
		
	}
	enemyHealth = team[enemy].takeDamage(damage);

	if (i < 0)
	{
		std::cout << "RETALIATION!\n" << std::endl;
	}
	else
	{
		std::cout << "Grunt " << +i << " attacks." <<std::endl;
	}
	std::cout << "Grunt " << +enemy << " took " << damage << " damage!" << " Grunt " << +enemy << " has " << enemyHealth << " health!\n" << std::endl;
	return false;
}

int grunt::retalliate()
{
	int retDamage;
	
	retDamage = rand() % 11;

	return retDamage;
}

void grunt::status(size_t teamSize, grunt * team)
{
	for (int i = 0; i < teamSize; i++)
	{
		std::cout << team[i].health << std::endl;
	}
}

int grunt::takeDamage(int damage)
{
	health -= damage;
		if (health < 0)
		{
			health = 0;
		}
		return health;

}

bool grunt::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	return false;
}