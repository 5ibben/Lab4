#pragma once
#include "MotorVehicle.h"
#include <vector>
using namespace std;

//Vehicle creating functions, returns a MotorVehicle object with specified data.
MotorVehicle uno()
{
	float tireDim[] = { 145,145,145,145 };
	MotorVehicle vehicle = MotorVehicle(tireDim, 4, "Fiat Uno\t",1000);
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
	MotorVehicle vehicle = MotorVehicle(tireDim, 2, "Crescent compact",500);
	vehicle.setBody(Body("Sport red", 0.40, 0.85));
	vehicle.changeEngine(Engine(0.05, 1,"Sachs 50cc Original"));
	return vehicle;
}

//other functions
void vehicleVectorPop(vector<MotorVehicle>* veh,int index)
{//Removes element at given index
	vector<MotorVehicle> temp =*veh;
	(*veh).clear();
	for (int i = 0; i < temp.size(); i++)
	{
		if (i!=index)
			(*veh).push_back(temp[i]);
	}
}
void engineVectorPop(vector<Engine>* veh, int index)
{//Removes element at given index
	vector<Engine> temp = *veh;
	(*veh).clear();
	for (int i = 0; i < temp.size(); i++)
	{
		if (i != index)
			(*veh).push_back(temp[i]);
	}
}

void main()
{
	int credits = 10000;
	vector<Engine> classifieds = { Engine(7.2,8,"Chrysler 440 ci RB V8",2400),Engine(0.07,1,"Sachs 70cc, mikuni 20",350),Engine(1.3,4,"Old 1,3L Saab engine\T",200) };
	vector<Engine> engines;
	vector<MotorVehicle> garage;
	vector<MotorVehicle> carDealer = { uno(),barracuda(),compact() };
	
	string name;
	string address;

	//User Input
	cout << "\nWelcome to 'PIMP MY UNO'!\n\n";
	cout << "Enter name:"; getline(cin, name);
	cout << "Enter Adress:"; getline(cin, address);

	garage.push_back(compact());
	garage[0].changeOwner(Owner(name,address));
	
	
	int input;
	bool menu=true;
	//Main menu
	while (menu)
	{
		bool submenu = true;
		cout << "\n1: Enter garage\n2: Visit car Dealer\n3: View the classifieds\n4: Take a ride\n0: Exit\n\n";
		cout << "Input: "; cin >> input; cout << endl;

		switch (input)
		{
		case 1://Garage
			cout << "\tGARAGE\tVehicles: " << garage.size() << "\n\n";
			for (int i = 0; i < garage.size(); i++)
			{
				cout <<"\t"<<i+1<<":\t"<< garage[i].getModel()<<"\n";
			}
			cout <<"\t0:\tExit\n";
			int selected;
			cout << "Input: "; cin >> selected;
			if (0<selected && selected <=garage.size())//Garage/selected
			{
				while (submenu)//Submenu
				{
					cout << "\n\t" << garage[selected - 1].getModel() << "\tMoney: " << credits << "\n";
					cout << "\n\t1: Inspect vehicle\n\t2: Repaint vehicle (200$)\n\t3: Replace engine\n\t4: Sell vehicle ("<< garage[selected - 1].getValue()/2<<"$)\n\t0: Exit\n";
					cout << "Input: "; cin >> input;
					cout << "\n\t"<< garage[selected - 1].getModel()<<":\n\n";
					switch (input)
					{
					case 1://Garage/selected/info
						garage[selected-1].print();
						break;
					case 2://Garage/selected/repaint
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
					case 3://Garage/selected/replace engine
						if (0<engines.size())
						{
							cout << "\tSelect Engine:\n";
							for (int i = 0; i < engines.size(); i++)
							{
								cout << "\t" << i + 1 << ": " << engines[i].getModel() << endl;
							}
							cout << "\t0: Exit\nInput: "; cin >> input;
							if (0 < input && input <= engines.size())
							{
								Engine temp = garage[selected - 1].getEngine();
								garage[selected - 1].changeEngine(engines[input - 1]);
								engines[input - 1] = temp;
							}
						}
						else
							cout << "\nYou got no engines in storage!\n";
						break;
					case 4://Garage/selected/Sell
						credits += garage[selected - 1].getValue() / 2;
						carDealer.push_back(garage[selected - 1]);
						vehicleVectorPop(&garage, selected - 1);
					case 0://Garage/selected/Exit
						submenu = false;
						break;
					default:
						break;
					}
				}
			}
			break;
		case 2://view car dealer
			while (submenu)//Submenu
			{
				cout << "\n\tCAR DEALER\t\tMoney: " << credits<<"$\n\n";
				for (int i = 0; i < carDealer.size(); i++)
				{
					cout <<"\t"<< i+1 << ": " << carDealer[i].getModel() <<"\tCost: "<<carDealer[i].getValue()<<"$\n";
				}
				cout << "\t0: Exit\n\nInput: "; cin >> input;
				if (0<input&&input<=carDealer.size())
				{
					if (carDealer[input - 1].getValue() < credits)
					{
						credits -= carDealer[input - 1].getValue();
						garage.push_back(carDealer[input - 1]);
						vehicleVectorPop(&carDealer, input - 1);
					}
					else
						cout << "\nNot enough money!\n";
				}
				else
					submenu = false;
			}
			break;
		case 3://view classifieds
			while (submenu)//Submenu
			{
				cout << "\n\tCLASSIFIEDS\t\t\tMoney: " << credits << "$\n\n";
				for (int i = 0; i < classifieds.size(); i++)
				{
					cout << "\t" << i + 1 << ": " << classifieds[i].getModel() << "\tCost: " << classifieds[i].getValue() << "$\n";
				}
				cout << "\t0: Exit\n\nInput: "; cin >> input;
				if (0 < input&& input <= classifieds.size())
				{
					if (classifieds[input - 1].getValue()<credits)
					{
						credits -= classifieds[input - 1].getValue();
						engines.push_back(classifieds[input - 1]);
						engineVectorPop(&classifieds, input - 1);
					}
					else
						cout << "\nNot enough money!\n";
				}
				else
					submenu = false;
			}
			break;
		case 4://Take a ride
			cout << "\tChoose a vehicle:\n\n";
			for (int i = 0; i < garage.size(); i++)
			{
				cout << "\t" << i + 1 << ":\t" << garage[i].getModel() << "\n";
			}
			cout << "\t0:\tExit\n";
			selected;
			cout << "Input: "; cin >> selected;
			if (0 < selected && selected <= garage.size())
			{
				cout << "\nYou went for a sweeet ride in you cool " << garage[selected - 1].getModel()<<endl;
			}
			break;
		case 0://exit
			menu = false;
			break;
		default:
			break;
		}
	}
}