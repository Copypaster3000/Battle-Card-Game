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


//assignemtn
attack_card & attack_card::operator = (const attack_card & og_attack)
{
	if(this == &og_attack) return *this; //Check for self assignment

	if(phrase) delete[] phrase; //if phrase has value, deallocate memory

	phrase = new char[strlen(og_attack.phrase) + 1]; //allocate memory
	strcpy(phrase, og_attack.phrase); //Set phrase value
	strength = og_attack.strength; //Set data members
	type = og_attack.type;

	return *this;
}


	

//destructor
attack_card::~attack_card(void)
{
	delete[] phrase; //Deallocate memory
}


//displays card stats to user
void attack_card::display(void)
{
	cout << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Type: " << type << endl;
	if(strength > 400) cout << phrase;

	return;
}


//Subtracts attack strength from opponents health
void attack_card::deal_damage(int & health)
{
	health = health - strength;

	return;
}



int attack_card::get_strength(void) const
{
	return strength;
}


	
int attack_card::get_type(void) const
{
	return type;
}


