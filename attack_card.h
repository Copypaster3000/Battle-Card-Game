//attack_card.h
//Drake Wheeler
//6/27/2024
//This is the header file for the attack_card class which is a derivation of the card class. This class enables
//clients to interact with attack_card data members, which are the stats of attack cards in the game. This class
//enables clients to display card stats to users and helps facilitate battles that involve attack cards.

#ifndef ATTACK_CARD_H
#define ATTACK_CARD_H

#include "card.h"


class attack_card : public card
{
	public:
		attack_card(void); //default constructor, Sets card attributes to half power
		attack_card(const string & name, int str, int typ); //constructor Sets name, strength, and attack type to values passed in
		attack_card(const attack_card &); //copy constructor
		~attack_card(void); //destructor
		attack_card & operator = (const attack_card &); //assignment 
		int display(void) const; //Displays card stats, returns 1 for success, 0 for error
		int get_strength(void) const; //Returns strength
		int get_type(void) const; //returns attack type
	

	private:
		char* phrase; //Used to taunt other player if attack strength is over 400
		int strength; //strength level of the attack card
		int type; //attack type of the card

};


#endif // ATTACK_CARD_H

