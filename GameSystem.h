#pragma once
#include "Player.h"
#include "Level.h"
#include <string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFile);

	void playGame();
	void playerMove();

private:
	Player _player;
	Level _level;
};

