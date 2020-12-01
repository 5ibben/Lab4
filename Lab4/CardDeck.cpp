#include "CardDeck.h"
#include <iostream>

CardDeck::CardDeck(bool jokers)
{
	deckSize = 52+3*jokers;
	deck = new Card[deckSize];
	for (color c = clubs; c <= spades; c = color(c + 1))
	{
		for (int i = 0; i < 13; i++)
		{
			deck[i+c*13] = Card(i+1, c);
			//std::cout << "i= " << i << " c= " << c << std::endl;
		}
	}
	
}

void CardDeck::print()
{
	for (int i = 0; i < deckSize; i++)
	{
		std::cout <<"at index "<<i<<": ";
		deck[i].print(); 
		std::cout << std::endl;
	}
}
