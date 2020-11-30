#pragma once
enum color { clubs, diamonds, hearts, spades };
class Card
{
public:
	Card(color = clubs, int = 1);
	color farg() { return col; }
	int value() { return val; }
	void print();
private:
	color col;
	int val;
};

