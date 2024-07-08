//heal_card.cpp
//Drake Wheeler
//

#include "heal_card.h"


//constructor
heal_card::heal_card(int str) : card("Heal Card"), strength(str)
{}


//destructor
heal_card::~heal_card(void)
{}


//displays card stats to user
void heal_card::display(void)
{
	cout << name << endl;
	cout << "Heal Strength: " << strength << endl;

	return;
}


//increases health passed in by heal card's strength
int heal_card::heal_up(int & p_health)
{
	p_health += strength;

	return 0;
}



