//heal_card.h
//Drake Wheeler
//6/27/2024
//This is the header file for the heal_card class which is a derivation of the card class. This class manages heal cards,
//can heal player's health, and allow clients to manage the heal card's strength.

#ifndef HEAL_CARD_H
#define HEAL_CARD_H
#include "card.h"


class heal_card : public card
{
	public:
		heal_card(void); //Default constructor
		heal_card(const string & nm, int str); //Constructor, pass in name as string and strength lvl
		~heal_card(void); //Destructor
		int display(void) const; //Displays cards stats, returns 1 for success, 0 for error
		int heal_up(void) const; //Returns heal strength to add to player's health
		int super_charge(void); //Sets strength to 1000, returns 1 for success
		int sabotage(void); //Sets strength to -1000, returns 1 for success


	private:
		int strength; //Heal card's strength level


};


#endif // HEAL_CARD_H

