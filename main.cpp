#include "main.h"
#include "Item.h"
#include <list>
#include <string>

using namespace std;

int main()
{
	Item sword("Sword", 150);
	Item axe("Axe", 150);
	int choice;

	cout << "Add a sword: 1\nAdd an axe: 2" << endl;
	cout << "Your Choice: ";
	cin >> choice;
	cout << "\nSuccess!\n";

	if (choice = 1)
	{
		sword.add();
	}

	else if (choice = 2)
	{
		axe.add();
	}

	cout << "Sword: " << sword.getCount() << endl;
	cout << "Axe: " << axe.getCount() << endl;



	//Exit success.
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "\nPress enter key to exit...";
	cin.ignore();
	return 0;
}