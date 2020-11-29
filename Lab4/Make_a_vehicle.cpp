#include "MotorVehicle.h"




MotorVehicle uno()
{
	float tireDim[] = { 145,145,145,145 };
	MotorVehicle vehicle = MotorVehicle(tireDim, 4, "Fiat Uno");
	vehicle.setBody(Body("An ugly shade of blue", 1.5, 1.4));
	vehicle.changeEngine(Engine(0.9, 4));
	return vehicle;
}

MotorVehicle barracuda()
{
	float tireDim[] = { 215,215,235,235 };
	MotorVehicle vehicle = MotorVehicle(tireDim, 4, "Plymouth Barracuda");
	vehicle.setBody(Body("Bahama Yellow", 1.9, 1.3));
	vehicle.changeEngine(Engine(0.9, 4));
	return vehicle;
}
MotorVehicle compact()
{
	float tireDim[] = { 110,110};
	MotorVehicle vehicle = MotorVehicle(tireDim, 2, "Cresent compact");//(tireDim, 2, "Cresent compact");
	vehicle.setBody(Body("Sport red", 0.40, 0.85));
	vehicle.changeEngine(Engine(0.05, 1));
	return vehicle;
}

void main()
{
	string name="Kalle";
	int credits = 1000;
	int vehicles = 1;
	
	MotorVehicle garage[2];
	MotorVehicle moped= compact();
	moped.changeOwner(Owner(name));
	garage[0] = moped;
	
	int input;
	bool menu=true;
	while (menu)
	{
		cout << "Input: "; cin >> input;
		switch (input)
		{
		case 1:
			cout << "In garage (" << vehicles << "/2)Vehicles.\n";
			for (int i = 0; i < vehicles; i++)
			{
				cout <<"\n\t"<<i+1<<":\t"<< garage[i].getModel();
			}
			cout <<"\n\t0:\tExit\n";
			int selected;
			cout << "\nInput: "; cin >> selected;
			if (0<selected && selected <=vehicles)
			{
				while (menu)
				{
					cout << "\n\t1: Inspect vehicle\n\t2: Repaint vehicle(200$)\n\t3: Replace engine(700$)\n\t4: Sell vehicle";// << garage[selected-1].getValue();
					cout << "Input: "; cin >> input;
					switch (input)
					{
					case 1:
						garage[selected-1].print();
					case 2:
						//repaint
					case 3:
						//replace engine
					case 4:
						//Sell
					case 0:
						menu = false;
						break;
					default:
						break;
					}
				}
			}
			break;
		case 2:
			//view car dealer
			break;
		case 3:
			//view classifieds
			break;
		case 4:
			//Take a ride
			break;
		case 0:
			//exit
			menu = false;
			break;
		default:
			cout << "\nInvalid input.\n";
			break;
		}
	}
	
}