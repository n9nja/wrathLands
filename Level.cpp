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
			case '@':
				player.setPosition(j, i);
				printf("Player position set to ");
				std::cout << j << ' ' << i << endl;
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
		printf("You ran into a wall!\n");
		system("PAUSE");
		break;
	}
}