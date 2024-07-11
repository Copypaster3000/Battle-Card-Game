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


//default constructor
player::player(void) : name(""), health(1000), card_choice(1), attack_head(nullptr), defense_rear(nullptr)
{}


//constructor
//sets players name to string passed in, health to 1000, and creates 100 heal cards in the vector
player::player(string nm, int offset) : name(nm), health(1000), card_choice(1), attack_head(nullptr), defense_rear(nullptr)
{
	//Generates a random seed for creating cards with random stats
	srand(time(NULL) + offset);

	//Creates objects of node classes to user their functions to create data structures of cards
	lll_node attack_cards; 
	cll_node defense_cards; 

	//Creates data scruture of each type of card
	if(!attack_cards.create_lll(attack_head, 100)) cout << "Error creating lll of attack cards." << endl;
	if(!defense_cards.create_cll(defense_rear, 100)) cout << "Error creating cll of defense cards." << endl;
	if(!create_heal_deck(100)) cout << "\nError creating vector of heal card." << endl; 
}


//destructor
player::~player(void)
{
	delete attack_head;
	delete defense_rear;

}


//Displays playes health and name
int player::display_health(void) const
{
	if(name.empty()) return 0; //error

	cout << name << "'s health lvl: " << health << endl;

	return 1; //success
}


//Gets card choice from user and sets player data memeber
//Returns 1 for success or 0 for invalid input
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
	if(choice == 1 || choice == 2 || choice == 3) return 1;
	
	return 0;
}


//Displays players current chosen card
int player::display_card(void) const
{
	cout << name << "'s card: " << endl;

	if(card_choice == 1)
	{
		//returns error if no card in deck
		if(!attack_head) return 1;

		//displays card stats	
		if(!attack_head->display()) cout << "\nError displaying attack card." << endl;
	}
	else if(card_choice == 2)
	{
		if(!defense_rear) return 1;//Returns  error if no card in deck
		if(!defense_rear->display()) cout << "\nError displaying defense card." << endl;
	}
	else if(card_choice == 3)
	{
		if(heal_cards.empty()) return 1;
		if(!heal_cards.back().display()) cout << "\nError displaying heal card." << endl; //Displays heal card or error message is there is one
	}
	else return 1; //Returns error if card choice is invalid

	cout << "\n"<< endl;

	return 0; //For success
}



//Pass in the other player object by reference
int player::attack_v_defend(player* & other_player) const
{
	//Returns 0 if it is an attack vs defense card round
	if((card_choice == 1 && other_player->card_choice == 2) || (card_choice == 2 && other_player->card_choice == 1)) return 1;

	return 0;
}


//plass in other player's class object
int player::battle(player* & other_player)
{
	//Returns error if other_player is nullptr
	if(!other_player) return 0;

	if(attack_v_defend(other_player)) //If an attack and defend card are both played this round
	{
		//Deals appropriate damage to defending player
		if(card_choice == 1) other_player->health -= other_player->defense_rear->defense(*attack_head);
		else health -= defense_rear->defense(*other_player->attack_head);
		//Adds heal from player's defense card to their health
		if(card_choice ==2) health += defense_rear->heal_up();
		else other_player->health += other_player->defense_rear->heal_up();

	}
	else //No attacks are being defended
	{
		//Deal attack damage to other player's health
		if(card_choice == 1) other_player->health -= attack_head->get_strength();
		if(other_player->card_choice == 1) health -= other_player->attack_head->get_strength();

		//Heals player's health if they chose defense card
		if(card_choice == 2) health += defense_rear->heal_up();
		if(other_player->card_choice == 2) other_player->health += other_player->defense_rear->heal_up();

		//Increases player's health with heal card strength if they played a heal card
		if(card_choice == 3) health += heal_cards.back().heal_up();
		if(other_player->card_choice == 3) other_player->health += other_player->heal_cards.back().heal_up();
	}

	return 1;
}



//Updates card decks
int player::update_decks(void)
{
	if(card_choice == 1) //if last card played is an attack card
	{
		if(!attack_head->next_card(attack_head)) //Deletes last attack card played, if there is an error doing that..
		{
			cout << "\nError removing attack card from deck." << endl;
			return 0; //For error
		}
	}
			

	if(card_choice == 2) //if last card played was a defense card
	{
		if(!defense_rear->next_card(defense_rear)) //deletes last defense card player, if there is an error doing that..
		{
			cout << "\nError removing defense card from deck." << endl;
			return 0; //Returns 0 for error
		}
	}

	if(card_choice == 3) 
	{
		if(heal_cards.empty())
		{
			cout << "\nError, heal card deck is empty." << endl;
			return 0;
		}
		else
			heal_cards.pop_back();
	}


	return 1;
}



//Creates vector of heal cards
int player::create_heal_deck(int num_cards)
{
	for(int i = 0; i < num_cards; ++i)
	{
		heal_cards.push_back(heal_card("Heal Card", rand() % 100 + 200));
	}

	return 1;
}


//retuns 1 if player is dead, 0 if not	
int player::dead(void) const
{
	if(health <= 0) return 1;

	return 0;
}


//returns winning message
int player::won(void) const
{
	if(health <= 0) return 0;

	cout << "\n********************************************" << endl;
    cout << "*                                          *" << endl;
    cout << "*                Victory!                  *" << endl;
    cout << "*                                          *" << endl;
    cout << "********************************************" << endl;
    cout << "                                            " << endl;
    cout << "    Well done, *" << name << "*!            " << endl;
    cout << "    You defeated your opponent with         " << endl;
    cout << "    " << health << " health left.           " << endl;
    cout << "                                            " << endl;
    cout << "********************************************" << endl;
    cout << "\nThe game is now over.\n" << endl;

	return 1;
}







	













	
