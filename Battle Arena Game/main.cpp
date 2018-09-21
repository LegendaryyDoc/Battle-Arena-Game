#include <iostream>
#include <ctime>
#include "Grunt.h"

size_t teamA = 10;
size_t teamB = 10;

bool gruntAlive(grunt *teamArr, size_t arrSize)
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

int main()
{
	srand(time(NULL));

	grunt aTeam[10];
	grunt bTeam[10];

	while (gruntAlive(aTeam, 10) && gruntAlive(bTeam, 10))
	{
		if (gruntAlive(aTeam, 10) && gruntAlive(bTeam, 10)) // if anyone is still living
		{
			for (int i = 0; i < teamA; i++)
			{
				aTeam[i].attack(i, bTeam, 10);
			}
		}
	}

	return 0;
}