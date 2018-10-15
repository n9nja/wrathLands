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