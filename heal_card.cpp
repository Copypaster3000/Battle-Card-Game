//heal_card.cpp
//Drake Wheeler
//

#include "heal_card.h"


//constructor
heal_card::heal_card(void) : card("Heal Card"), strength(250)
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


