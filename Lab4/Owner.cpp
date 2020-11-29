#include "Owner.h"

void Owner::print()
{
	cout << "\nOwner:";
	cout << "\n\tName: " << name << "\n\tAddress: " << address<<"\n\tIs allowed to drive: ";
	if (allowedToDrive)
		cout << "Yes!\n";
	else
		cout << "No!\n";
}
