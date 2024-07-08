//heal_card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file holds the class definitions for the heal class

#include "heal_card.h"


//default constructor
heal_card::heal_card(void) : card("Heal Card"), strength(250)
{}


//constructor
heal_card::heal_card(const string & nm, int str) : card(nm), strength(str)
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


//returns strength to add to player's health
int heal_card::heal_up(void)
{
	return strength;
}



