#include "MotorVehicle.h"




MotorVehicle uno()
{
	float tireDim[] = { 145,145,145,145 };
	MotorVehicle vehicle = MotorVehicle(tireDim, 4, "Fiat Uno",1000);
	vehicle.setBody(Body("An ugly shade of blue", 1.5, 1.4));
	vehicle.changeEngine(Engine(0.9, 4));
	return vehicle;
}

MotorVehicle barracuda()
{
	float tireDim[] = { 215,215,235,235 };
	MotorVehicle vehicle = MotorVehicle(tireDim, 4, "Plymouth Barracuda",10200);
	vehicle.setBody(Body("Bahama Yellow", 1.9, 1.3));
	vehicle.changeEngine(Engine(7.0, 8));
	return vehicle;
}
MotorVehicle compact()
{
	float tireDim[] = {110,110};
	MotorVehicle vehicle = MotorVehicle(tireDim, 2, "Cresent compact",500);
	vehicle.setBody(Body("Sport red", 0.40, 0.85));
	vehicle.changeEngine(Engine(0.05, 1));
	return vehicle;
}

void main()
{
	string name="Kalle";
	string address = "Kallegatan 5";
	int credits = 1000;
	int vehicles = 1;
	MotorVehicle garage[2];
	MotorVehicle carDealer[3] = { uno(),barracuda(),compact()};
	Engine engines[10];

	float tireDim[] = { 110,110 };
	MotorVehicle vehicle1 = barracuda();
	vehicle1.changeOwner(Owner(name));
	vehicle1.print();
	
	/*
	MotorVehicle bil1 = MotorVehicle(tireDim, 2, "Cresent compact"); //tilldelningsoperatorn kallas
	MotorVehicle bil2 = bil1; //copyconstructor gets called
	MotorVehicle bil3;
	bil3 = bil1; //tilldelningsoperatorn kallas
	bil2.print();
	*/

	garage[0] = vehicle1;
	//cout << garage[0].getValue();
	
	int input;
	bool menu=true;
	while (menu)
	{
		cout << "Input: "; cin >> input;
		switch (input)
		{
		case 1://Garage
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
				bool submenu = true;
				while (submenu)
				{
					cout << "Money left: " << credits;
					cout << "\n\t1: Inspect vehicle\n\t2: Repaint vehicle (200$)\n\t3: Replace engine (700$)\n\t4: Sell vehicle ("<< garage[selected - 1].getValue()/2<<"$)\n\t0: Exit\n";
					cout << "Input: "; cin >> input;
					switch (input)
					{
					case 1:
						garage[selected-1].print();
						break;
					case 2:
						//repaint
						if (200<=credits)
						{
							string color;
							cin.ignore();
							cout << "\nWhat color would you like? ";
							getline(cin, color);
							garage[selected - 1].changeColor(color);
							credits -= 200;
						}
						else
							cout << "Come back when you got enough money pal!";
						cout << endl;
						break;
					case 3:
						//replace engine
					case 4:
						//Sell
					case 0:
						submenu = false;
						break;
					default:
						break;
					}
				}
			}
			break;
		case 2:
			//view car dealer
			for (int i = 0; i < 3; i++)
			{
				cout << i+1 << ": " << carDealer[i].getModel() <<"\tCost: "<<carDealer[i].getValue()<<endl;
			}
			cout << "\n0: Exit\nInput: "; cin >> input;
			if (1<input<4)
			{
				credits -= carDealer[input-1].getValue();
				garage[1] = carDealer[input - 1];
				garage[1].changeOwner(Owner(name, address));
				vehicles++;
			}
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