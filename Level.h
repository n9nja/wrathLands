#pragma once
#include <vector>
#include <string>

#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
public:
	Level();
	//Load and print the level
	void load(string fileName, Player &player);
	void print();
	//Movement stuff
	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);

	//Getters
	char getTile(int x, int y);
	//Setters
	void setTile(int x, int y, char tile);


private:
	vector <string> _levelData;
	vector <Enemy> _enemies;

	void processMove(Player &player, int targetX, int targetY);
	void enemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
};