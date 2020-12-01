#pragma once
#include <string>

class Body
{
public:
	Body(std::string _color = "Unknown", float _width = 2, float _height = 1.5)
		:color(_color), width(_width), height(_height) {}
	void print();
private:
	std::string color;
	float width, height;
};

