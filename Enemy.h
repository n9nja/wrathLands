#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	//Constructs enemies
	Enemy(string name, char tile, int level, int attack, int defense, int health, int xp);

	//Setters
	void setPosition(int x, int y);

	//Getters
	void getPosition(int &x, int &y);
	string getName() { return _name; }

	//Attack
	int attack();
	int takeDamage(int attack);



private:
	//Basic details
	string _name;
	char _tile;

	//Stats
	int _attack;
	int _defense;
	int _health;
	int _experienceValue;
	int _level;

	//Position
	int _x;
	int _y;
};