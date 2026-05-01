#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <list>
#include <algorithm> // for std::find
#include <string>

#include "Player.h"
#include "Goblin.h"

std::list<std::string> leatherBootsRecipe = { "Leather", "String" };

void printMenu() {
	std::cout << "Goblin Warfare: Windows 11 Edition (Alpha 3)" << std::endl;
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
		Player player("player", 1000, 100, 1, 0, 100, 0, 0, 10, 0, false, {}, 1000);
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
			auto& inventory = player.getInventory();
			if ((std::find(inventory.begin(), inventory.end(), "Holy Scriptures") != inventory.end())
				&& (std::find(inventory.begin(), inventory.end(), "Leather boots") != inventory.end())) {
				std::cout << "You gathered all forbidden items.\n";
				pause(2);
				std::cout << "You also decided to not use the usable ones.\n";
				pause(2);
				std::cout << "Pretty brave of you...\n";
				pause(2);
				std::cout << "What have you done?\n";
				pause(2);
				std::cout << "I'll give you a moment to realize the consequences...";
				pause(2);
				return 0;
			}
			std::cout << "What do you want to do?" << std::endl;
			std::cout << "1. Fight" << std::endl;
			std::cout << "2. Buy" << std::endl;
			std::cout << "3. Use Item" << std::endl;
			std::cout << "4. Craft" << std::endl;
			std::cout << "5. Quit" << std::endl;
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
						std::cout << "You used the holy sciptures, the ultimate weapon in all of OmVille... You can see the goblin tremble in fear. He's dead." << std::endl;
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
						player.addToInventory("String");
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
							return 0;
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
				std::cout << "6. Leather - Used in crafting (10 Gold)" << std::endl;
				std::cout << "7. Exit" << std::endl;
				int purchase;
				std::cin >> purchase;
				if (purchase == 1 && player.getGold() >= 100) {
					player.addToInventory("Health Potion");
					std::cout << "Added a health potion to inventory" << std::endl;
					pause(1);
				}
				else if (purchase == 2 && player.getGold() >= 10) {
					player.addToInventory("Steak");
					std::cout << "Added a steak to inventory" << std::endl;
					pause(1);
				}
				else if (purchase == 3 && player.getGold() >= 20) {
					player.addToInventory("Apple");
					std::cout << "Added an apple to inventory" << std::endl;
					pause(1);
				}
				else if (purchase == 4 && player.getGold() >= 5000) {
					player.addToInventory("Holy Scriptures");
					std::cout << "Added the holy scriptures to inventory" << std::endl;
					pause(1);
				}
				else if (purchase == 5 && player.getGold() >= 100) {
					player.addToInventory("LVLUP Potion");
					pause(1);
				}
				else if (purchase == 6 && player.getGold() >= 10) {
					player.addToInventory("Leather");
					pause(1);
				}
				else if (purchase == 7) {
					choice = NULL;
				}
				else {
					std::cout << "Not enough money, or incorrect choice." << std::endl;
					choice = NULL;
					pause(1);
				}
			}
			else if (choice == 3) {
				if (player.getInventory().empty()) {
					std::cout << "Your inventory is empty";
					pause(1);
				}
				else {
					std::cout << "Your items:" << std::endl;
					for (std::string item : player.getInventory()) {
						std::cout << "- " << item << std::endl;
					}
					std::cout << "Which item do you want to use: ";
					std::string item;
					std::getline(std::cin >> std::ws, item);
					if (item == "Health Potion") {
						if (player.getMaxHealth() - player.getHealth() >= 100) {
							player.heal(100);
						}
						else {
							player.heal(player.getMaxHealth() - player.getHealth());
						}
					}
					else if (item == "Steak") {
						player.eat(10);
					}
					else if (item == "Apple") {
						if (player.getHealth() < 100) {
							player.heal(1);
						}
						player.eat(10);
					}
					else if (item == "Holy Scriptures") {
						player.giveScriptures();
					}
					else if (item == "LVLUP Potion") {
						player.giveXp(player.getXpTilNextLevel() - player.getXp());
						player.levelUp();
					}
					else if (item == "Leather") {
						std::cout << "You can't use this item here!" << std::endl;
						pause(1);
					}
				}
			}
			else if (choice == 4) {
				std::cout << "Craftable Items:" << std::endl;
				auto& inventory = player.getInventory();
				if ((std::find(inventory.begin(), inventory.end(), "Leather") != inventory.end())
					&& (std::find(inventory.begin(), inventory.end(), "String") != inventory.end())) {
					std::cout << "- Leather Boots" << std::endl;
				}
				std::string answer;
				std::cout << "Enter the name of the item you wanna craft, or type exit: ";
				std::getline(std::cin >> std::ws, answer);
				if (answer == "exit") {
					continue;
				}
				else if (answer == "Leather Boots") {
					// check materials and craft
					if ((std::find(inventory.begin(), inventory.end(), "Leather") != inventory.end())
						&& (std::find(inventory.begin(), inventory.end(), "String") != inventory.end())) {
						// remove materials and add crafted item
						player.removeFromInventory("Leather");
						player.removeFromInventory("String");
						player.addToInventory("Leather Boots");
						std::cout << "You crafted Leather Boots." << std::endl;
						pause(1);
						continue;
					}
					else {
						std::cout << "You don't have the required materials." << std::endl;
						pause(1);
						continue;
					}
				}
			}
			else if (choice == 5) {
				return 0;
			}
		}
	}
	else if (choice == 2) {
		return 0;
	}
	return 0;
}