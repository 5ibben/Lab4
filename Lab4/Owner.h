#pragma once
#include <string>
#include <iostream>
using namespace std;

class Owner
{
public:
	Owner(string _name = "Unknown", string _address = "Unknown", bool _allowedToDrive = true)
		:name(_name), address(_address), allowedToDrive(_allowedToDrive){}
	void print();
private:
	string name, address;
	bool allowedToDrive;
};

