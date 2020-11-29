#include "MotorVehicle.h"

MotorVehicle::MotorVehicle(float* _tireDiameters, int _numberOfTires, string _model)
{
	numberOfTires = _numberOfTires; model = _model;
	if (_tireDiameters)
	{
		tireDiameters = new float[numberOfTires];
		for (int i = 0; i < numberOfTires; i++)
		{
			tireDiameters[i] = _tireDiameters[i];
		}
	}
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
