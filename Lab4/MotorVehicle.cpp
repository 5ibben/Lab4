#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(float* _tireDiameters, int _numberOfTires, string _model,int _value)
	:tireDiameters(_tireDiameters), numberOfTires(_numberOfTires), model(_model),value(_value)
{
	numberOfTires = _numberOfTires; model = _model;// value = _value;
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

void MotorVehicle::changeColor(string _color)
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

string MotorVehicle::getModel()
{
	return model;
}


int MotorVehicle::getValue()
{
	return value;
}



void MotorVehicle::print()
{
	cout << "\nVehicle Data:\n";
	cout<<"\nModel:\n\t" << model << endl;
	owner.print();
	engine.print();
	body.print();
	cout << "\nTires:\n\tNumber of tires: " << numberOfTires << "\n\tTire Diameters: ";
	if (tireDiameters)
	{
		for (int i = 0; i < numberOfTires; i++)
		{
			if (0 < i)
				cout << "\t\t\t";
			cout << tireDiameters[i] << endl;
		}
	}
	else
		cout << "Unknown\n";
}
