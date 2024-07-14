//card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file holds the class definitions for the card class. The functions manage the card name
//which is a char* pointer that holds the cards name which is dynamically allocated. 

#include "card.h"


//default constructor, set name to nullptr
card::card(void) : name(nullptr)
{}


//constructor
//this allows you to set the cards strength, card_move, and move_type when the object is created
card::card(const string & str) : name(nullptr)
{
	name = new char[str.size() + 1]; //Allocates memory dynamically for card type
	strcpy(name, str.c_str()); //Sets name with string
}


//copy constructor
card::card(const card & object) 
{
	name = new char[strlen(object.name) + 1]; //Allocates correct amount of memory for name
	strcpy(name, object.name); //Copies name
}


//destructor
card::~card(void)
{
	//deallocates memory
	delete[] name;
}


//assignment
card & card::operator = (const card & og_card)
{
	if(this == &og_card) return *this; //Check for self assignment

	if(name) delete[] name; //If name has value, deallocate memory

	name = new char[strlen(og_card.name) + 1]; //Allocate correct memory
	strcpy(name, og_card.name); //Copies name

	return *this;
}


//Pass in new name of card
int card::change_name(string & new_name)
{
	if(name) delete[] name; //deallocate old memory
					   
	name = new char[new_name.size() + 1]; //Allocates memory dynamically for new name
	strcpy(name, new_name.c_str()); //Sets name with string

	return 1; //for success
}


//Changes name to cool name
int card::ultimate_name(void)
{
	if(name) delete[] name; //deallocates old memory

	name = new char[strlen("Destroyer of Worlds") + 1]; //allocates memory dynamically 
	strcpy(name, "Destroyer of Worlds"); //sets new cool name to name

	return 1; //returns success
}


//Deletes name, sets it to nullptr
int card::delete_name(void)
{
	if(name) //If there is something at name
	{
		delete[] name; //Delete it
		name = nullptr; //Set it to null
	}

	return 1; //Success
}


