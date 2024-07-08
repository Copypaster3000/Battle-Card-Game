//defense_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the defense_card class which is a derivation of the card class
//

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
		int defend(const lll_node & attack_card); //Defends against attack, returns the amount of damage done to defending player's health
		int heal_me(int & health); //Heal's players health by heal

	protected:
		int strength;
		int type;
		int heal;
		
};


#endif // DEFENSE_CARD_H
