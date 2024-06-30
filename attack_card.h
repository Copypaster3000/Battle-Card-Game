//attack_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the attack_card class which is a derivation of the card class

#ifndef ATTACK_CARD_H
#define ATTACK_CARD_H

#include "card.h"


class attack_card : public card
{
	public:
		attack_card(void); //Sets card attributes to half power
		attack_card(const char* name, int str, int typ); //Sets name, strength, and attack type to values passed in
		~attack_card(void);
		void display(void); //Displays card stats

	private:
		int strength;
		int type;

};


#endif // ATTACK_CARD_H

