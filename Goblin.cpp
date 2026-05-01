#include "Goblin.h"
#include "Player.h"

Goblin::Goblin(int level, int scoreValue, int health, int attackPower, int goldReward) 
	: level(level), scoreValue(scoreValue), health(health), attackPower(attackPower), goldReward(goldReward) {};

void Goblin::attack(Player player) {
	player.takeDamage(attackPower);
	if (player.getHealth() <= 0) {
		std::cout << "You died" << std::endl;
	}
}

int Goblin::getHealth() {
	return health;
}

void Goblin::takeDamage(int points) {
	health = health - points;
}

int Goblin::getGoldValue() {
	return goldReward;
}