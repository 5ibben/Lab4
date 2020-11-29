#pragma once
#include <iostream>
using namespace std;

class Engine
{
public:
	Engine(float _sizeInLitres=2, int _numberOfCylinders=4)
	{
		sizeInlitres = _sizeInLitres; numberOfCylinders = _numberOfCylinders;
	}
	void print();
private:
	float sizeInlitres;
	int numberOfCylinders;
};

