#include "Player.h"



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

//Gets player position by reference
void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}