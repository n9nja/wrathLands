/*

Wrath Lands - An ASCII Adventure Game
Copyright (C) 2018  Charles Hancock

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

Level::Level()
{
}

void Level::load(string fileName, Player &player)
{
	//Load the level
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();


	//Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			case '@': //Player
				player.setPosition(j, i);
				break;
			case 'S': //Snake
				_enemies.push_back(Enemy("Snake", tile, 1000000, 3, 1, 10, 10));
				_enemies.back().setPosition(j, i);
				break;
			case 'g':
				_enemies.push_back(Enemy("Snake", tile, 2, 7, 4, 30, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'D':
				_enemies.push_back(Enemy("Dragon", tile, 7, 12, 10, 100, 1000));
				_enemies.back().setPosition(j, i);
				break;
			case 'A':
				_enemies.push_back(Enemy("Assassin", tile, 3, 9, 7, 80, 100));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}
}

void Level::print()
{

	std::cout << string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player &player)
{

	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);

	switch (input) {
	case 'w':  //Up
	case 'W':
		processMove(player, playerX, playerY - 1);
		break;
	case 's':  //Down
	case 'S':
		processMove(player, playerX, playerY + 1);
		break;
	case 'a':  //Left
	case 'A':
		processMove(player, playerX - 1, playerY);
		break;
	case 'd':  //Right
	case 'D':
		processMove(player, playerX + 1, playerY);
		break;
	case 'k':
	case 'K':
		break;
	default:
		printf("INVALID INPUT!\n");
		break;
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::processMove(Player &player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char  moveTile = getTile(targetX, targetY); 

	switch (moveTile) {
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

void Level::battleMonster(Player &player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int attackRoll;
	int attackResult;
	string enemyName;

	for (int i = 0; i < _enemies.size(); i++) {
		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();

		if (targetX == enemyX && targetY == enemyY) {
			//Battle!
			attackRoll = player.attack();

			printf("Player attacked %s with a roll of %d", enemyName.c_str(), attackRoll);

			attackResult = _enemies[i].takeDamage(attackRoll);
			if (attackResult != 0) {
				setTile(targetX, targetY, '.');
				print();
				printf("Monster died!\n");
				player.addExperience(attackResult);
				system("PAUSE");

				return;
			}
			//Monster turn
			attackRoll = _enemies[i].attack();

			printf("%s attacked Player with a roll of %d", enemyName.c_str(), attackRoll);

			attackResult = player.takeDamage(attackRoll);

			if (attackResult != 0) {
				setTile(targetX, targetY, 'x');
				print();
				printf("YOU DEAD\n");
				system("PAUSE");

				exit(0);
			}


			return;
		}
	}
}