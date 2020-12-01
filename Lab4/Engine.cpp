#include "Engine.h"
#include <iostream>

int Engine::getValue()
{
	return value;
}

std::string Engine::getModel()
{
	return model;
}

void Engine::print()
{
	std::cout << "\nEngine:\n\tModel:"<<model;
	std::cout << "\n\tEngine volume: " << sizeInlitres << "\n\tNumber of cylinders: " << numberOfCylinders << std::endl;
}
