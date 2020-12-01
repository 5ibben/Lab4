#pragma once
#include <string>

class Owner
{
public:
	Owner(std::string _name = "Unknown", std::string _address = "Unknown", bool _allowedToDrive = true)
		:name(_name), address(_address), allowedToDrive(_allowedToDrive){}
	void print();
private:
	std::string name, address;
	bool allowedToDrive;
};

