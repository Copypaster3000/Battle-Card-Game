//attack_card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the attack_card class which manages attack cards

#include "attack_card.h"


//default constructor, sets card attributes to hald power
attack_card::attack_card(void) : card("Attack Card"), strength(250), type(1)
{}

//constructor, sets card attributes to values passed in
attack_card::attack_card(const char* name, int str, int typ) : card(name), strength(str), type(typ)
{}


//destructor
attack_card::~attack_card(void)
{}


//displays card stats to user
void attack_card::display(void)
{
	cout << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Type: " << type << endl;

	return;
}


	


