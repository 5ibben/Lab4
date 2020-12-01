#include "Body.h"
#include <iostream>

void Body::print()
{
	std::cout << "\nBody:";
	std::cout << "\n\tColor: " << color << "\n\tWidth: " << width << "\n\tHeight: " << height<<" meters\n";
}
