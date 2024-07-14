//heal_card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file holds the class definitions for the heal class. These functions enable healing
//a player's health by returning the strength which is directly added to payer's health. They display
//card stats the users using cout. They edit the card stats by changing the card's data members.

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
int heal_card::display(void) const
{
	if(!name) return 0; //for error

	cout << name << endl;
	cout << "Heal Strength: " << strength << endl;

	return 1; //for success
}


//returns strength to add to player's health
int heal_card::heal_up(void) const
{
	return strength;
}


//Sets strenght to 1000
int heal_card::super_charge(void)
{
	strength = 1000;

	return 1; //Returns 1 for success
}


//Sabotages the heal card setting strength to -1000
int heal_card::sabotage(void)
{
	strength = -1000;

	return 1; //returns 1 for success
}

