#include <iostream>
#include <ctime>
#include "Grunt.h"
#include <windows.h>

void outputColor(std::string text, int col);

size_t aSize = 10;
size_t bSize = 10;

const int BLUE = 0x09;
const int RED = 0x04;
const int DEFAULT = 0x07;

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
	bool endgame = false;



	while (gruntAlive(aTeam, aSize) && gruntAlive(bTeam, bSize) && !endgame)
	{
		if (gruntAlive(aTeam, aSize) && gruntAlive(bTeam, bSize)) // if anyone is still living
		{
			for (size_t i = 0; i < aSize && !endgame; i++)
			{
				if (aTeam[i].isAlive())
				{
					outputColor("Team A is attacking!\n", RED);

					endgame = aTeam[i].attack(i, bTeam, bSize); // prints out what is happening with damage and the action

					outputColor("Team B is retaliating!\n", BLUE);

					endgame = bTeam[0].attack(-1, aTeam, aSize); // prints out what is happening with damage and the action

				}
			}
			outputColor("Team A", RED);

			aTeam[10].status(aSize, aTeam); // printing out Team A health

			outputColor("\nTeam B", BLUE);

			bTeam[10].status(bSize, bTeam); // printing out Team B health
			system("pause");
		}
		if (gruntAlive(aTeam, aSize) && gruntAlive(bTeam, bSize)) // if anyone is still living
		{
			for (size_t i = 0; i < aSize && !endgame; i++)
			{
				if (bTeam[i].isAlive())
				{
					outputColor("Team B is attacking!\n", BLUE);

					endgame = bTeam[i].attack(i, aTeam, aSize); // prints out what is happening with damage and the action
					
					outputColor("Team A is retaliating!\n", RED);

					endgame = aTeam[0].attack(-1, bTeam, bSize); // prints out what is happening with damage and the action 
				}
			}
			outputColor("Team A", RED);

			aTeam[10].status(aSize, aTeam); // printing out Team A health

			outputColor("\nTeam B", BLUE);

			bTeam[10].status(bSize, bTeam); // printing out Team B health
		}

	}
	if (gruntAlive(aTeam, aSize)) // Team A win
	{
		outputColor("\nTeam A has won!", RED);

		system("pause");
		return 0;
	}
	if (gruntAlive(bTeam, bSize)) // Team B win
	{
		outputColor("\nTeam B has won!", BLUE);

		system("pause");
		return 0;
	}
	else if (!gruntAlive(aTeam, aSize) && !gruntAlive(bTeam, bSize))
	{
		std::cout << "The war was brutal and neither team came out alive!" << std::endl;
		system("pause");
		return 0;
	}
	return 0;

}
void outputColor(std::string myText, int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);

	std::cout <<  myText.c_str() << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);
}
