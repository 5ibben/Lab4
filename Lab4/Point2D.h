#pragma once
#include <string>
#include <math.h>	//todo: overlo0ad operators: +, =, ==
class Point2D
{
public:
	Point2D();//default constructor
	Point2D(float _x, float _y);//initialize constructor
	Point2D(const Point2D& other);//copy constructor

	Point2D operator+(const Point2D& other) const;//addition operator
	bool operator==(const Point2D& other) const;//bool operator
	const Point2D& operator=(const Point2D& other);//assignment operator

	float distance(Point2D other);
	std::string toString();
private:
	float x, y;
};

