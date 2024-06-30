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


//Default constructor
player::player(void) : name("Anonymous"), health(1000), heal_cards(100)
{
	//Generates a random seed for creating cards with random stats
	srand(time(NULL));

	//Creats objects of node classes to user their functions to create data structures of cards
	lll_node attack_cards; 
	cll_node defense_cards; 

	//Displays a warning if there is an error creating the LLL of attack cards
	if(attack_cards.create_lll(attack_head, 100)) cout << "Error creating lll of attack cards." << endl;
	if(defense_cards.create_cll(defense_rear, 100)) cout << "Error creating cll of defense cards." << endl;
}


//constructor
//sets players name to string passed in, health to 1000, and creates 100 heal cards in the vector
player::player(char* nm) : name(nm), health(1000), heal_cards(100)
{
	//Generates a random seed for creating cards with random stats
	srand(time(NULL));

	//Creats objects of node classes to user their functions to create data structures of cards
	lll_node attack_cards; 
	cll_node defense_cards; 

	//Displays a warning if there is an error creating the LLL of attack cards
	if(attack_cards.create_lll(attack_head, 100)) cout << "Error creating lll of attack cards." << endl;
	if(defense_cards.create_cll(defense_rear, 100)) cout << "Error creating cll of defense cards." << endl;
}


//destructor
player::~player(void)
{


}






	
