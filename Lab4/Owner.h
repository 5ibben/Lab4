#pragma once
#include <string>
#include <iostream>
using namespace std;

class Owner
{
public:
	Owner(string _name="Unknown", string _adress= "Unknown", bool _allowedToDrive = true)
	{
		name = _name; address = _adress; allowedToDrive = _allowedToDrive;
	}
	void print();
private:
	string name, address;
	bool allowedToDrive;
};

