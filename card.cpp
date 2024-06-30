//card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the card class definitions

#include "card.h"
#include "cstring"


//default constructor
card::card(void) : name(nullptr)
{}


//constructor
//this allows you to set the cards strength, card_move, and move_type when the object is created
card::card(const char* str)
{
	name = new char[strlen(str) + 1]; //Allocates memory dynamically for card type
	strcpy(name, str);
	
}


//destructor
card::~card(void)
{
	//deallocates memory
	delete[] name;
}


