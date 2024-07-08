//defense_card.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the defense card class which manages defense cards

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
int defense_card::defend(const lll_node & attack_card)
{
	int damage = 0;
	int defended = 0;

	if(attack_card.get_type() == this->type) //If the defense card does defend against attack
	{
		//Sets defended to amount of attack that was defended
		if(this->strength <= attack_card.get_strength()) defended = this->strength;
		else defended = attack_card.get_strength();

		damage = attack_card.get_strength() - this->strength; //Sets damage to damage done to defending player's health
		cout << "The defense card blocked " << defended << " of the attack." << endl; //Displays how much of the attack was defended to users
		if(damage > 0)

		return damage; //Returns damage
	}
	else cout << "The attack was not defended." << endl;


	return attack_card.get_strength(); //Returns total attack strength for not being defended
}


//increases health passed in by cards heal lvl
int defense_card::heal_me(int & health)
{
	health += heal;

	return 0;
}









