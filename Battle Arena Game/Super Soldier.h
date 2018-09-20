#pragma once

class superSoldier
{
	int armor = 50;
	int health = 100;
	int attack();

	void takeDamage(int damage);

	bool isAlive();
};