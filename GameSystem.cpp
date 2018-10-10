#include "GameSystem.h"
#include <iostream>
#include <conio.h>


//Constructor sets up the game
GameSystem::GameSystem(string levelFile)
{
	_player.init(1, 100, 10, 10, 0);

	_level.load(levelFile, _player);
	

	system("PAUSE");
}

void GameSystem::playGame() {

	bool isDone = false;
	
	while (isDone != true) {
		_level.print();
		playerMove();
	}
}


//Movement
void GameSystem::playerMove() {
	char input;
	printf("Move with WASD: ");
	input = _getch();

	_level.movePlayer(input, _player);
}