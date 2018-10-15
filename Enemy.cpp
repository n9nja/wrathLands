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