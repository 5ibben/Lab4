#pragma once
#include "Engine.h"
#include "Body.h"
#include "Owner.h"

class MotorVehicle
{
public:
	MotorVehicle(float* _tireDiameters = nullptr, int _numberOfTires = 4, string _model = "Unknown",int _value=0);//constructor
	~MotorVehicle() {delete[] tireDiameters;}//destructor
	MotorVehicle(const MotorVehicle& other);//copy constructor
	const MotorVehicle& operator=(const MotorVehicle& other);//assignment operator
	const MotorVehicle& operator=(MotorVehicle&& other) noexcept;//assignment move operator
	
	//class functions
	void changeOwner(Owner _owner);
	void changeColor(string _color);
	void changeEngine(Engine _engine);
	void changeTires(float* _tireDiameters);
	void setBody(Body _body);
	void print();
	int getValue();
	string getModel();
	Engine getEngine();
private:
	float* tireDiameters; // dynamically allocated array!
	int numberOfTires;
	int value;
	Owner owner;
	Body body;
	string model;
	Engine engine;
};

