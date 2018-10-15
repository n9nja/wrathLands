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

#include "Enemy.h"
#include <random>
#include <ctime>

using namespace std;



Enemy::Enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;
}

//Sets enemy position
void Enemy::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

//Gets enemy position by reference
void Enemy::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}

int Enemy::attack() {
	static default_random_engine randomEngine(time(0));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack) {
	attack -= _defense;
	//Check for damage
	if (attack > 0) {
		_health -= attack;
		//Did he died?
		if (_health <= 0) {
			return _experienceValue;
		}
	}
	return 0;
	}