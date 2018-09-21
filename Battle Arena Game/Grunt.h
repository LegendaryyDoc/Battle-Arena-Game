#pragma once

class grunt
{
public:

	int armor = 0;
	int health = 10;
	int attack(int I, grunt * team, size_t teamLimit);
	int retalliate();

	void takeDamage(int damage);

	bool isAlive();
};