//defense_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the defense_card class which is a derivation of the card class. This class can be used to facilitate
//defending against an attack card, healing a player with the defense card's heal lvl, and editing defense card stats

#ifndef DEFENSE_CARD_H
#define DEFENSE_CARD_H

#include "card.h"
#include "lll_node.h"


class defense_card : public card
{
	public:
		defense_card(void); //Sets card attributes to half power
		defense_card(string name, int str, int type, int heal); //Sets card attributes to values passed in
		~defense_card(void);
		int defend(const lll_node & attack_card) const; //Defends against attack, returns the amount of damage done to defending player's health, displays to player amount of attack blocked
		int heal_me(void); //Returns heal value to be added to player's health
		int super_charge(void); //Super charges this cards stats, returns 1 for success

	protected:
		int strength; //Holds the defense strength of the card
		int type; //Holds the defense type of the card
		int heal; //holds the heal strength of the card
		
};


#endif // DEFENSE_CARD_H
