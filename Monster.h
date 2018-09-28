#pragma once
#include <string>

using namespace std;


class Monster
{

public:
	Monster(string name);
	void printName();

private:
	string _name;
};

