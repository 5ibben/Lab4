#pragma once
#include <iostream>
using namespace std;

class Engine
{
public:
	Engine(float _sizeInLitres = 2, int _numberOfCylinders = 4, string _model = "Unknown", int _value = 0)
		:sizeInlitres(_sizeInLitres), numberOfCylinders(_numberOfCylinders), value(_value), model(_model) {}
	int getValue();
	string getModel();
	void print();
private:
	float sizeInlitres;
	int numberOfCylinders;
	int value;
	string model;
};

