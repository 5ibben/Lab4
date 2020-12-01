#include "Polyline.h"
#include <iostream>
#include <cassert>

Polyline::Polyline()
	:pointArray(nullptr),numberOfPoints(0),arrayLength(10){}

Polyline::Polyline(int _arrayLenght)
	: pointArray(nullptr),numberOfPoints(0),arrayLength(_arrayLenght){}

Point2D& Polyline::operator[](int i)
{
	assert(0 <= i && i < arrayLength);
	return pointArray[i];
}

void Polyline::add(Point2D other)
{
	if (numberOfPoints<arrayLength)
	{
		if (numberOfPoints == 0)
		{
			pointArray = new Point2D[arrayLength];
		}
		(*this)[numberOfPoints]=other;
		numberOfPoints++;
	}else
		std::cout << "ERROR! can not add. Polyline is full!\n";
}

void Polyline::removeLast()
{
	if (0<numberOfPoints)
	{
		numberOfPoints--;
		if (numberOfPoints==0)
		{
			delete[] pointArray;
			pointArray = nullptr;
		}
	}
	else
		std::cout << "ERROR! can not remove. Polyline is empty!\n";
}

bool Polyline::contains(Point2D other)
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		if (other== (*this)[i])
		{
			return true;
		}
	}
	return false;
}

int Polyline::points()
{
	return numberOfPoints;
}

float Polyline::length()
{
	float len=0;
	if (1<numberOfPoints)
	{
		for (int i = 1; i < numberOfPoints; i++)
		{
			len += (*this)[i].distance((*this)[i-1]);
		}
	}
	return len;
}

void Polyline::print()
{
	for (int i = 0; i < numberOfPoints; i++)
	{
		std::cout << (*this)[i].toString()<<std::endl;
	}
}
