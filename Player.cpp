#include "Player.h"
#include "Goblin.h"

Player::Player(std::string name, int health, int hunger, int level, int xp, int xpTilNextLevel, int score, int gold, int damage)
	: name(name), health(health), hunger(hunger), level(level), xp(xp), xpTilNextLevel(xpTilNextLevel), score(score), gold(gold), damage(damage) {};

int Player::getHealth() {
	return health;
}

std::string Player::getName() {
	return name;
}

int Player::getXp() {
	return xp;
}

int Player::getXpTilNextLevel() {
	return xpTilNextLevel;
}

int Player::getScore() {
	return score;
}

int Player::getHunger() {
	return hunger;
}

int Player::getDamage() {
	return damage;
}

int Player::getGold() {
	return gold;
}

void Player::takeDamage(int points) {
	health = health - points;
}

void Player::heal(int points) {
	health = health + points;
}

void Player::eat(int points) {
	hunger = hunger + points;
}

void Player::loseHunger(int points) {
	hunger = hunger - points;
}

void Player::giveGold(int points) {
	gold = gold + points;
}