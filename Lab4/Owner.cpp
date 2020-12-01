#include "Owner.h"
#include <iostream>

void Owner::print()
{
	std::cout << "\nOwner:";
	std::cout << "\n\tName: " << name << "\n\tAddress: " << address<<"\n\tIs allowed to drive: ";
	if (allowedToDrive)
		std::cout << "Yes!\n";
	else
		std::cout << "No!\n";
}
