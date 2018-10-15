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

#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <random>
#include <ctime>
#include <string>
#include "GameSystem.h"

using namespace std;

static default_random_engine levelEngine(time(0));
uniform_int_distribution<int> level(1, 2);


int main()
{
	int lvlNum = level(levelEngine);
	string levelName = "level" + to_string(lvlNum) + ".wl";
	GameSystem gameSystem(levelName);
	gameSystem.playGame();

	return 0;
}