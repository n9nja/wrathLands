#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameSystem.h"

using namespace std;

int main()
{
	GameSystem gameSystem("level1.wl");
	gameSystem.playGame();

	return 0;
}