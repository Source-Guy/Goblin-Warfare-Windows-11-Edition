#include "Player.h"

Player::Player(std::string name, int health, int hunger, int level, int xp, int xpTilNextLevel, int score, int gold, int damage, int armor, bool hasScriptures,
	std::list<std::string> inventory, int maxHealth)
	: name(name), health(health), hunger(hunger), level(level), xp(xp), xpTilNextLevel(xpTilNextLevel), score(score), gold(gold), damage(damage), armor(armor),
	hasScriptures(hasScriptures), inventory(inventory), maxHealth(maxHealth) {
};

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

int Player::getLevel() {
	return level;
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

void Player::levelUp() {
	if (xp >= xpTilNextLevel) {
		xpTilNextLevel = xpTilNextLevel * 2;
		level++;
		maxHealth = maxHealth + 10;
		damage = damage + 20;
	}
}

void Player::takegold(int points) {
	gold = gold - points;
}

int Player::getArmor() {
	return armor;
}

bool Player::getScripturesStatus() {
	return hasScriptures;
}

void Player::giveScriptures() {
	hasScriptures = true;
}

void Player::takeScriptures() {
	hasScriptures = false;
}

void Player::giveXp(int points) {
	xp = xp + points;
}

std::list<std::string>& Player::getInventory() {
	return inventory;
}

void Player::addToInventory(std::string item) {
	inventory.push_front(item);
}

void Player::removeFromInventory(const std::string& item) {
	inventory.remove(item);
}

void Player::addMaxHealth(int points) {
	maxHealth = maxHealth + points;
}

int Player::getMaxHealth() {
	return maxHealth;
}