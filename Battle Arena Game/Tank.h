#pragma once

class tank
{
	int armor = 100;
	int health = 100;
	int attack();

	void takeDamage(int damage);

	bool isAlive();
};