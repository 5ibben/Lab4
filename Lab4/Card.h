#pragma once
enum color { clubs, diamonds, hearts, spades };
class Card
{
public:
	Card(int = 0, color = clubs);//constructor

	//member functions
	color farg() { return col; }
	int value() { return val; }
	void print();
private:
	color col;
	int val;
};

