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
defense_card::defense_card(const char* name, int str, int typ, int hl) : card(name), strength(str), type(typ), heal(hl)
{}


//destructor
defense_card::~defense_card(void)
{}


//Deals damage to health passed in based on attack card passed in and this defense card stats
int defense_card::defend(const lll_node & attack_card, int & health)
{
	int damage = 0;

	if(attack_card.get_type() == this->type) 
	{
		damage = attack_card.get_strength() - this->strength;
		cout << "The defense card blocked up to " << this->strength << " of the attack." << endl;
		if(damage > 0) health = health - damage;
	}
	else cout << "The attack was not defended." << endl;


	return 0;
}


//increases health passed in by cards heal lvl
int defense_card::heal_me(int & health)
{
	health += heal;

	return 0;
}









