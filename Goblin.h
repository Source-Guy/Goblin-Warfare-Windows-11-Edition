#pragma once

#include "Player.h"

class Goblin {
private:
	int health;
	int level;
	int attackPower;
	int scoreValue;
	int goldReward;

public:
	Goblin(int level, int scoreValue, int health, int attackPower, int goldReward);
	void attack(Player player);
	int getHealth();
	void takeDamage(int points);
	int getGoldValue();
};