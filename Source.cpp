#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Goblin.h"

void printMenu() {
	std::cout << "Goblin Warfare: Windows 11 Edition (Alpha 1.0)" << std::endl;
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
	printMenu();
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		Player player("player", 100, 100, 1, 0, 100, 0, 0, 10);
		while (true) {
			clearScreen();
			std::cout << "What do you want to do?" << std::endl;
			std::cout << "1. Fight" << std::endl;
			std::cout << "2. Buy" << std::endl;
			std::cout << "3. Quit" << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				std::cout << "You found a goblin!" << std::endl;
				pause(2);
				Goblin goblin(1, 100, 50, 10, 10);
				while (true) {
					goblin.attack(player);
					goblin.takeDamage(player.getDamage());
					if (player.getHealth() <= 0) {
						break;
					}
					else if (goblin.getHealth() <= 0) {
						std::cout << "You killed the goblin!" << std::endl;
						pause(1);
						player.loseHunger(21);
						if (player.getHunger() <= 0) {
							player.takeDamage(10);
						}
						player.giveGold(goblin.getGoldValue());
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
				std::cout << "3. Exit" << std::endl;
				int purchase;
				std::cin >> purchase;
				if (purchase == 1 && player.getGold() >= 100) {
					player.heal(10);
					pause(1);
				}
				else if (purchase == 2 && player.getGold() >= 10) {
					player.eat(10);
					pause(1);
				}
				else if (purchase == 3) {
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