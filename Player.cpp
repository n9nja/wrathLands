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

#include "Player.h"
#include <random>
#include <ctime>

using namespace std;



Player::Player()
{
	_x = 0;
	_y = 0;
}

//Player initialization
void Player::init(int level, int health, int attack, int defense, int experience) {
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

//Sets player position
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

//Add experience
void Player::addExperience(int experience) {
	_experience += experience;

	while (_experience > 50) {

		printf("Leveled up!\n");
		_experience -= 50;
		_attack += 10;
		_defense += 5;
		_health += 10;
		_level++;
		system("PAUSE");
	}
}

//Gets player position by reference
void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

int Player::attack() {
	static default_random_engine randomEngine(time(0));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Player::takeDamage(int attack) {
	attack -= _defense;
	//Check for damage
	if (attack > 0) {
		_health -= attack;
		//Did he died?
		if (_health <= 0) {
			return 1;
		}
	}
	return 0;
}