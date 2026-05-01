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
		int armor;
		bool hasScriptures;

public:
	Player(std::string name, int health, int hunger, int level, int xp, int xpTilNextLevel, int score, int gold, int damage, int armor, bool hasScriptures);
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
		void levelUp();
		int getLevel();
		void takegold(int points);
		int getArmor();
		bool getScripturesStatus();
		void giveScriptures();
		void takeScriptures();
		void giveXp(int points);
};