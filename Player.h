#pragma once

#include <iostream>

class Player {
private:
	std::string name;
	int health;
	int hunger;
	int level;
	int xp;
	int xpTilNextLevel;
	int score;
	int gold;
	int damage;

public:
	Player(std::string name, int health, int hunger, int level, int xp, int xpTilNextLevel, int score, int gold, int damage);
	void takeDamage(int points);
	std::string getName();
	int getHealth();
	int getGold();
	int getXp();
	int getXpTilNextLevel();
	int getScore();
	int getHunger();
	int getDamage();
	void heal(int points);
	void eat(int points);
	void loseHunger(int points);
	void giveGold(int points);
};