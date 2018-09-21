#pragma once

class grunt
{
public:

	int armor = 0;
	int health = 10;
	bool attack(int i, grunt * team, size_t teamLimit);
	int retalliate();
	void status(size_t teamSize, grunt * team);

	int takeDamage(int damage);

	bool isAlive();

private:
	bool gruntAlive(grunt *teamArr, size_t arrSize);
};