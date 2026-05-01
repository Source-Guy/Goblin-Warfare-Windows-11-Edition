#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "Player.h"
#include "Goblin.h"

void printMenu() {
	std::cout << "Goblin Warfare: Windows 11 Edition (Alpha 2)" << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
}

void pause(int seconds) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void clearScreen() {
	std::cout << "\033[2J\033[1;1H";
}

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	printMenu();
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		Player player("player", 1000, 100, 1, 0, 100, 0, 0, 10, 0, false);
		std::cout << "You, a young kid, heard a legend about the holy scriptures..." << std::endl;
		pause(1);
		std::cout << "For in seven days Yahweh created the earth..." << std::endl;
		pause(1);
		std::cout << "But you doubted..." << std::endl;
		pause(1);
		std::cout << "You decided to try to get them." << std::endl;
		std::cout << "Goal: win a battle while holding The Holy Scriptures" << std::endl;
		system("pause");
		while (true) {
			clearScreen();
			std::cout << "What do you want to do?" << std::endl;
			std::cout << "1. Fight" << std::endl;
			std::cout << "2. Buy" << std::endl;
			std::cout << "3. Quit" << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				int min = player.getLevel() - 1;
				int max = player.getLevel() + 3;
				std::uniform_int_distribution<> distrib(min, max);
				int randomNumber = distrib(gen);
				std::cout << "You found a goblin!" << std::endl;
				pause(1);
				Goblin goblin(randomNumber, randomNumber * 100, randomNumber * 50, randomNumber * 3, randomNumber * 10);
				while (true) {
					if (player.getScripturesStatus() == false) {
						player.takeDamage(goblin.getDamage());
					}
					else {
						std::cout << "You purchased the holy sciptures, the ultimate weapon in all of Gutville... You can see the goblin tremble in fear. He's dead." << std::endl;
					}
					goblin.takeDamage(player.getDamage());
					if (player.getHealth() <= 0) {
						break;
					}
					else if (goblin.getHealth() <= 0) {
						std::cout << "You killed the goblin!" << std::endl;
						player.loseHunger(10);
						pause(1);
						player.levelUp();
						std::cout << "Your remaining HP: " << player.getHealth() << std::endl;
						std::cout << "Your remaining Food Points: " << player.getHunger() << std::endl;
						pause(2);
						if (player.getHunger() <= 0) {
							player.takeDamage(10);
							std::cout << "You took damage because you're hungry" << std::endl;
							pause(1);
						}
						player.giveGold(goblin.getGoldValue());
						if (player.getScripturesStatus()) {
							std::cout << "What the shop keeped didn't tell you, is that using the scriptures against your enemies with curse you..." << std::endl;
							std::cout << "\"Do not seek revenge or bear a grudge against anyone among your people, but love your neighbor as yourself. I am Yahweh.\"" << std::endl;
							pause(5);
							player.takeScriptures();
						}
						break;
					}
					else {
						continue;
					}
				}
				if (player.getHealth() <= 0) {
					break;
				}
			}
			else if (choice == 2) {
				clearScreen();
				std::cout << "Gold: " << player.getGold() << std::endl;
				std::cout << "1. Health potion - Heals 10 hp (100 Gold)" << std::endl;
				std::cout << "2. Steak - Decreases hunger by 10 (10 Gold)" << std::endl;
				std::cout << "3. Apple - Decreases hunger by 10 and heals 1 hp (20 Gold)" << std::endl;
				std::cout << "4. The Holy Scriptures - auto win 1 fight (5000 Gold)" << std::endl;
				std::cout << "5. LVLUP Potion - Instantly Level Up (100 Gold)" << std::endl;
				std::cout << "6. Exit" << std::endl;
				int purchase;
				std::cin >> purchase;
				if (purchase == 1 && player.getGold() >= 100) {
					player.heal(10);
					player.takegold(100);
					pause(1);
				}
				else if (purchase == 2 && player.getGold() >= 10) {
					player.eat(10);
					player.takegold(10);
					pause(1);
				}
				else if (purchase == 3 && player.getGold() >= 20) {
					player.eat(10);
					player.heal(1);
					player.takegold(20);
					pause(1);
				}
				else if (purchase == 4 && player.getGold() >= 5000) {
					if (player.getScripturesStatus() == true) {
						std::cout << "You already own this item" << std::endl;
					}
					else {
						player.giveScriptures();
						pause(1);
					}
				}
				else if (purchase == 5 && player.getGold() >= 100) {
					player.giveXp(player.getXpTilNextLevel() - player.getXp());
					pause(1);
				}
				else if (purchase == 6) {
					continue;
				}
				else {
					std::cout << "Not enough money, or incorrect choice." << std::endl;
				}
			}
			else if (choice == 3) {
				return 0;
			}
		}
	}
	else if (choice == 2) {
		return 0;
	}
	return 0;
}