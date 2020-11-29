#pragma once
#include "Engine.h"
#include "Body.h"
#include "Owner.h"

class MotorVehicle
{
public:
	MotorVehicle(float* _tireDiameters = nullptr, int _numberOfTires = 4, string _model = "Unknown",int _value=0);
	MotorVehicle(const MotorVehicle& other);//kopiering
	const MotorVehicle& operator=(const MotorVehicle& other);//tilldelning
	const MotorVehicle& operator=(MotorVehicle&& other) noexcept;//move version
	~MotorVehicle() {delete[] tireDiameters;}

	void changeOwner(Owner _owner);
	void changeColor(string _color);
	void changeEngine(Engine _engine);
	void changeTires(float* _tireDiameters);
	void setBody(Body _body);
	string getModel();
	int getValue();
	void print();
private:
	Engine engine;
	Body body;
	Owner owner;
	float* tireDiameters; // dynamically allocated array!
	int numberOfTires;
	string model;
	int value;
};

