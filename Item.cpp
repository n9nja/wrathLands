#include "Item.h"


Item::Item(string name, int value)
{
	_name = name;
	_value = value;
	_count = 0;
}

void Item::add()
{
	_count++;
}

void Item::remove()
{
	_count--;
}
