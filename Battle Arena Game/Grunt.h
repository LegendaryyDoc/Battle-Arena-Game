#pragma once

class grunt
{
	int armor = 0;
	int health = 100;
	int attack();

	void takeDamage(int damage);

	bool isAlive();
};