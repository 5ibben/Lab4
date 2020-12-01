#include "MotorVehicle.h"
#include <iostream>

MotorVehicle::MotorVehicle(float* _tireDiameters, int _numberOfTires, std::string _model,int _value)
	:tireDiameters(_tireDiameters), numberOfTires(_numberOfTires), model(_model),value(_value)
{
	if (_tireDiameters)
	{
		tireDiameters = new float[numberOfTires];
		for (int i = 0; i < numberOfTires; i++)
		{
			tireDiameters[i] = _tireDiameters[i];
		}
	}
}

MotorVehicle::MotorVehicle(const MotorVehicle& other)
	:engine(other.engine),body(other.body), owner(other.owner),numberOfTires(other.numberOfTires), model(other.model),value(other.value)
{
	tireDiameters = new float[numberOfTires];
	for (int i = 0; i < numberOfTires; i++)
	{
		tireDiameters[i] = other.tireDiameters[i];
	}
}

const MotorVehicle& MotorVehicle::operator=(const MotorVehicle& other)
{
	if (this != &other)
	{
		engine = other.engine;
		body = other.body;
		owner = other.owner;
		numberOfTires = other.numberOfTires;
		model = other.model;
		value = other.value;
		delete[] tireDiameters;
		tireDiameters = new float[numberOfTires];
		for (int i = 0; i < numberOfTires; i++)
		{
			tireDiameters[i] = other.tireDiameters[i];
		}
	}
	return *this;
}

const MotorVehicle& MotorVehicle::operator=(MotorVehicle&& other) noexcept
{
	if (this != &other)
	{
		engine = other.engine;
		body = other.body;
		owner = other.owner;
		numberOfTires = other.numberOfTires;
		model = other.model;
		value = other.value;
		delete[] tireDiameters;
		tireDiameters = other.tireDiameters;
		numberOfTires = other.numberOfTires;
		other.tireDiameters = nullptr;
		other.numberOfTires = 0;
	}
	return *this;
}

void MotorVehicle::changeOwner(Owner _owner)
{
	owner = _owner;
}

void MotorVehicle::changeColor(std::string _color)
{
	body = Body(_color);
}

void MotorVehicle::changeEngine(Engine _engine)
{
	engine = _engine;
}

void MotorVehicle::changeTires(float* _tireDiameters)
{
	delete[] tireDiameters;
	tireDiameters = new float[numberOfTires];
	for (int i = 0; i < numberOfTires; i++)
	{
		tireDiameters[i] = _tireDiameters[i];
	}
}

void MotorVehicle::setBody(Body _body)
{
	body = _body;
}

std::string MotorVehicle::getModel()
{
	return model;
}


int MotorVehicle::getValue()
{
	return value+engine.getValue();
}

Engine MotorVehicle::getEngine()
{
	return engine;
}



void MotorVehicle::print()
{
	std::cout << "\nVehicle Data:\n";
	std::cout<<"\nModel:\n\t" << model << std::endl;
	owner.print();
	engine.print();
	body.print();
	std::cout << "\nTires:\n\tNumber of tires: " << numberOfTires << "\n\tTire Diameters: ";
	if (tireDiameters)
	{
		for (int i = 0; i < numberOfTires; i++)
		{
			if (0 < i)
				std::cout << "\t\t\t";
			std::cout << tireDiameters[i] << std::endl;
		}
	}
	else
		std::cout << "Unknown\n";
}
