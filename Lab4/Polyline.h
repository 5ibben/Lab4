#pragma once
#include "Point2D.h"

class Polyline
{
public:
	Polyline();//default constructor
	Polyline(int _arrayLenght);//constructor
	~Polyline() { delete[] pointArray; }//destructor
	
	//member functions
	void add(Point2D other);
	void removeLast();
	void print();
	float length();
	int points();
	bool contains(Point2D other);
private:
	Point2D& operator[](int i);//index operator
	Point2D* pointArray;//dynamic array
	int arrayLength;
	int numberOfPoints;
};

