//attack_card.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file holds the function definitions for the attack_card class
//

#include "attack_card.h"


//default constructor, sets card attributes to hald power
attack_card::attack_card(void) : card("Attack Card"), strength(250), type(1)
{}


//constructor, sets card attributes to values passed in
attack_card::attack_card(const string & name, int str, int typ) : card(name), strength(str), type(typ)
{
	const char* at_phrase = "If you don't block this high strength of an attack you're toast!";
	phrase = new char[strlen(at_phrase) + 1];
	strcpy(phrase, at_phrase);

}


//copy constructor
attack_card::attack_card(const attack_card & object) : card(object.name), strength(object.strength), type(object.type)
{
	phrase = new char[strlen(object.phrase) + 1]; //allocates space of string
	strcpy(phrase, object.phrase); //copies string
}


//assignment
attack_card & attack_card::operator = (const attack_card & og_attack)
{
	if(this == &og_attack) return *this; //Check for self assignment

	card::operator=(og_attack); //Class base class card assignment operator

	if(phrase) delete[] phrase; //if phrase has value, deallocate memory

	phrase = new char[strlen(og_attack.phrase) + 1]; //allocate memory
	strcpy(phrase, og_attack.phrase); //Set phrase value
	strength = og_attack.strength; //Set data members
	type = og_attack.type;

	return *this; //Return new object that is now exactly the same
}
	

//destructor
attack_card::~attack_card(void)
{
	delete[] phrase; //Deallocate memory
}


//displays card stats to user
int attack_card::display(void) const
{
	if(!name) return 0; //Return error if there's no name

	cout << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Type: " << type << endl;
	if(strength > 400) cout << phrase; //Displays special phrase if this is an especially strong attack_card

	return 1; //for success
}


int attack_card::get_strength(void) const
{
	return strength;
}


	
int attack_card::get_type(void) const
{
	return type;
}


