#include "Monster.h"
#include <iostream>

Monster::Monster(string name)
{
	_name = name;
}

void Monster::printName()
{
	cout << "My name is " << _name << "." << endl;
}