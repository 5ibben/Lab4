#include "Engine.h"

int Engine::getValue()
{
	return value;
}

string Engine::getModel()
{
	return model;
}

void Engine::print()
{
	cout << "\nEngine:\n\tModel:"<<model;
	cout << "\n\tEngine volume: " << sizeInlitres << "\n\tNumber of cylinders: " << numberOfCylinders << endl;
}
