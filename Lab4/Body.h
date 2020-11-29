#pragma once
#include <string>
#include <iostream>
using namespace std;

class Body
{
public:
	Body(string _color="Unknown",float _width=2,float _height=1.5)
	{
		color = _color; width = _width; height = _height;
	}
	void print();
private:
	string color;
	float width, height;
};

