//card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the card class definitions
//

#include "card.h"


//default constructor
card::card(void) : name(nullptr)
{

}


//constructor
//this allows you to set the cards strength, card_move, and move_type when the object is created
card::card(const string & str)
{
	name = new char[str.size() + 1]; //Allocates memory dynamically for card type
	strcpy(name, str.c_str());
	
}


//copy constructor
card::card(const card & object) 
{
	name = new char[strlen(object.name) + 1];
	strcpy(name, object.name);
}


//assignment
card & card::operator = (const card & og_card)
{
	if(this == &og_card) return *this; //Check for self assignment

	if(name) delete[] name; //If name has value, deallocate memory

	name = new char[strlen(og_card.name) + 1]; //Allocate correct memory and assign value to name
	strcpy(name, og_card.name);

	return *this;
}




//destructor
card::~card(void)
{
	//deallocates memory
	delete[] name;
}


