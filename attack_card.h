//attack_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the attack_card class which is a derivation of the card class
//

#ifndef ATTACK_CARD_H
#define ATTACK_CARD_H

#include "card.h"


class attack_card : public card
{
	public:
		attack_card(void); //Sets card attributes to half power
		attack_card(const char* name, int str, int typ); //Sets name, strength, and attack type to values passed in
		attack_card(const attack_card &); //copy constructor
		~attack_card(void);
		void display(void); //Displays card stats
		void deal_damage(int & health); //Pass in the players health damage is being dealt to update health based on attack strength, use only when attack is not defended
		int get_strength(void) const; //Returns strength
		int get_type(void) const; //returns types
	

	private:
		char* phrase; //Used to taunt other player if attack strength is over 400
		int strength;
		int type;

};


#endif // ATTACK_CARD_H

