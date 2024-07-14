//defense_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the defense card class definitions. These functions can facilitate defending against
//an attack card by taking in an attack card object and comparing the stats to this card. The healing of a 
//defense card is facilitated here by returning the heal strength which is directly added to a player's health
//A function can also edit defense card stats by changing the card data members. 

#include "defense_card.h"


//defualt constructot, sets card atrributes to half power
defense_card::defense_card(void) : card("Defense Card"), strength(190), type(1), heal(62)
{}


//constructor, sets card attributes to values passed in
defense_card::defense_card(string name, int str, int typ, int hl) : card(name), strength(str), type(typ), heal(hl)
{}


//destructor
defense_card::~defense_card(void)
{}


//Returns the amount of damage done to defending players health
int defense_card::defend(const lll_node & attack_card) const
{
	int damage = 0; //Holds the damage done to player after defending attack
	int defended = 0; //Holds the amount at the attack strength defended 

	if(attack_card.get_type() == this->type) //If the defense card does defend against attack
	{
		//Sets defended to amount of attack that was defended
		//If attack is stronger than defense, sets defended to the total defense strength
		if(this->strength <= attack_card.get_strength()) defended = this->strength;
		else defended = attack_card.get_strength(); //Else if defense is stronger than attack, sets defended to total attack strength

		damage = attack_card.get_strength() - this->strength; //Sets damage to damage done to defending player's health
		cout << "The defense card blocked " << defended << " of the attack." << endl; //Displays how much of the attack was defended to users
		if(damage > 0) return damage; //Returns damage
		else return 0; //Returns 0 for when the defense over powers attack
	}
	else cout << "The attack was not defended." << endl;

	return attack_card.get_strength(); //Returns total attack strength for not being defended
}


//returns heal lvl of this defense card
int defense_card::heal_me(void)
{
	return heal;
}


//super charges defense card
int defense_card::super_charge(void)
{
	heal = 500;
	strength = 1000;

	return 1; //Returns 1 for success
}


