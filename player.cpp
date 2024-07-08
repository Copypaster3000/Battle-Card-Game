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
player::player(string nm, int offset) : name(nm), health(1000)
{
	//Generates a random seed for creating cards with random stats
	srand(time(NULL) + offset);

	//Creats objects of node classes to user their functions to create data structures of cards
	lll_node attack_cards; 
	cll_node defense_cards; 

	//Displays a warning if there is an error creating the LLL of attack cards
	if(attack_cards.create_lll(attack_head, 100)) cout << "Error creating lll of attack cards." << endl;
	if(defense_cards.create_cll(defense_rear, 100)) cout << "Error creating cll of defense cards." << endl;

	create_heal_deck(100); //Creats 100 heal_card's in player's vector member
}


//destructor
player::~player(void)
{


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

	cin.clear();
	cin.ignore(100, '\n'); //Clear input stream
						  

	card_choice = choice;

	//Returns 0 for success or 1 for invalid input
	if(choice == 1 || choice == 2 || choice == 3) return 0;
	
	return 1;
}


//Displays players current chosen card
int player::display_card(void)
{
	cout << name << "'s card: " << endl;

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



//Pass in the other player object by reference
int player::attack_v_defend(player* & other_player)
{
	//Returns 0 if it is an attack vs defense card round
	if((card_choice == 1 && other_player->card_choice == 2) || (card_choice == 2 && other_player->card_choice == 1)) return 0;

	return 1;
}


//plass in other player's class object
void player::battle(player* & other_player)
{
	//If an attack and defend card are both played this round
	if(!attack_v_defend(other_player))
	{
		//Deals appropriate damage to defending player
		if(card_choice == 1) other_player->health -= other_player->defense_rear->defense(*attack_head);
		else health -= defense_rear->defense(*other_player->attack_head);
		//Heals player that played defense card
		if(card_choice ==2) defense_rear->heal_up(health);
		else other_player->defense_rear->heal_up(other_player->health);

	}
	else //No attacks are being defended
	{
		//Deal attack damage to other player's health
		if(card_choice == 1) attack_head->deal_damage(other_player->health);
		if(other_player->card_choice == 1) other_player->attack_head->deal_damage(health);

		//Increases player's health with heal card strength if they played a heal card
		if(card_choice == 3) 
			if(heal_cards.back().heal_up(health)) cout << "Error healing player." << endl;

		if(other_player->card_choice == 3) 
			if(other_player->heal_cards.back().heal_up(other_player->health)) cout << "Error healing player." << endl;
	}

	return;
}



//Updates card decks
int player::update_decks(void)
{
	if(card_choice == 1) attack_head->next_card(attack_head); //Deletes card just played, makes next card new head

	if(card_choice == 2) defense_rear->next_card(defense_rear); //Removes card just played from deck

	if(card_choice == 3) heal_cards.pop_back();

	return 0;
}



//Creates vector of heal cards
void player::create_heal_deck(int num_cards)
{
	for(int i = 0; i < num_cards; ++i)
	{
		heal_cards.push_back(heal_card("Heal Card", rand() % 100 + 200));
	}

	return;
}


//retuns 1 if player is dead, 0 if not	
int player::dead(void)
{
	if(health <= 0) return 1;

	return 0;
}


//returns winning message
void player::won(void)
{
	cout << "\n********************************************" << endl;
    cout << "*                                          *" << endl;
    cout << "*                 Victory!                 *" << endl;
    cout << "*                                          *" << endl;
    cout << "********************************************" << endl;
    cout << "                                            " << endl;
    cout << "    Well done, *" << name << "*!            " << endl;
    cout << "    You defeated your opponent with         " << endl;
    cout << "    " << health << " health left.           " << endl;
    cout << "                                            " << endl;
    cout << "********************************************" << endl;
    cout << "\nThe game is now over.\n" << endl;

	return;
}







	













	
