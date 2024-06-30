//player.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the file for the player class definitions

#include "player.h"
#include <cstdlib>
#include <ctime>


//constructor
//sets players name to string passed in, health to 1000, and creates 100 heal cards in the vector
player::player(string nm) : health(1000), heal_cards(100)
{
	//Generates a random seed for creating cards with random stats
	srand(time(NULL));

	name = new char[nm.length() + 1];
	strcpy(name, nm.c_str());

	//Creats objects of node classes to user their functions to create data structures of cards
	lll_node attack_cards; 
	cll_node defense_cards; 

	//Displays a warning if there is an error creating the LLL of attack cards
	if(attack_cards.create_lll(attack_head, 100)) cout << "Error creating lll of attack cards." << endl;
	if(defense_cards.create_cll(defense_rear, 100)) cout << "Error creating cll of defense cards." << endl;
}


//Displays playes health and name, returns 0 if alive, 1 if dead
int player::display_health(void)
{
	cout << name << "'s health lvl: " << health << endl;

	if(health > 0) return 0;
	else return 1;
}


//Gets card choice from user and sets player data memeber
//Returns 0 for success or 1 for invalid input
int player::get_card_choice(void)
{
	int choice;

	cout << name << " select the type of card you would like to draw for this round." << endl;
	cout << "1) Attack" << endl;
	cout << "2) Defense" << endl;
	cout << "3) Heal" << endl;
	cout << "Enter your choice as an integer here: ";
	cin >> choice;
	cout << endl;

	card_choice = choice;

	//Returns 0 for success or 1 for invalid input
	if(choice == 1 || choice == 2 || choice == 3) return 0;
	else return 1;
}


//Displays players current chosen card
int player::display_card(void)
{
	cout << name << "'s card: \n" << endl;

	if(card_choice == 1)
	{
		//returns error if no card in deck
		if(!attack_head) return 1;

		//displays card stats	
		attack_head->display();
	}
	else if(card_choice == 2)
	{
		if(!defense_rear) return 1;
		defense_rear->display();
	}
	else if(card_choice == 3)
	{
		if(heal_cards.empty()) return 1;
		heal_cards.back().display();
	}
	else return 1; //Returns error if card choice is invalid

	cout << "\n"<< endl;

	return 0; //For success
}













//destructor
player::~player(void)
{


}






	
