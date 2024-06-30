//heal_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the heal_card class which is a derivation of the card class

#ifndef HEAL_CARD_H
#define HEAL_CARD_H
#include "card.h"


class heal_card : public card
{
	public:
		heal_card(void);
		~heal_card(void);
		void display(void); //Displays cards stats

	private:
		int strength;

};


#endif // HEAL_CARD_H

