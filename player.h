//player.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the player class
//

#ifndef PLAYER_H
#define PLAYER_H

#include "lll_node.h"
#include "cll_node.h"
#include "heal_card.h"
#include <vector>
#include <cstring>

using namespace std;

class player
{
    public:
		player(void); //default constructor
		player(string nm, int offset); //Constructor, pass in name of player, and unique offset for random num generator, creats player with full decks of each card
        ~player(void);
		int get_card_choice(void); //Gets card choice from user, sets data member, returns 1 for success or 0 for invalid input
		int display_health(void) const; //Displays players name and health lvl, returns 1 for success, 0 for error
		int display_card(void) const; //Displays players current card, returns 1 for error, 0 for success
		int battle(player* & other_player); //Facilitates battle round, Edits both player's health based on cards played this round, returns 1 for success, 0 for error
		int update_decks(void); //Removes card played that round from deck, returns 0 if a card deck becomes empty, 1 if not
		int dead(void) const; //returns 1 if player is dead, 0 if not
		int won(void) const; //Returns winning message, call when this player wins, returns 1 for success, or 0 if player's health is 0 or below


		
    private:
		string name; //Players custom name
		int health; //Players current health lvl
		int card_choice; //holds int to represent current card chioce, 1) attack, 2) defense, 3) heal
						 //
		lll_node* attack_head; //Holds attack cards
		cll_node* defense_rear; //Holds defense cards
		vector<heal_card> heal_cards; //holds heal cards

		int attack_v_defend(player* & other_player) const; //Returns 1 if one players has an attack card and the other a defense card, returns 0 otherwise
		int create_heal_deck(int str); //Creates vector heal_cards with as many elements as int passed in, returns 1 for success
};


#endif // PLAYER_H
