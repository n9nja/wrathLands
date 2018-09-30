#pragma once
#include <string>

using namespace std;

class Item
{
public:
	Item(string name, int value);

	void add();
	void remove();

	//Getters
	string getName() { return _name; };
	int getValue() { return _value; };
	int getCount() { return _count; };

	//Setters
	void setCount(int count) { _count = count; };

private:
	string _name;
	int _value;
	int _count;
};

