#include "GameSystem.h"
#include <iostream>
#include <conio.h>

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