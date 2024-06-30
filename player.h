//player.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the player class

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
		player(string nm); //Constructor, pass in name of player, creats player with full decks of each card
        ~player(void);
        int update_health(int impact); //Updates players health based off results from last battle
		int get_card_choice(void); //Gets card choice from user, sets data member, returns 0 for success or 1 for invalid input
		int display_health(void); //Displays players name and health lvl, return 1 if health < 0, and 0 if player is alive
		int display_card(void); //Displays players current card, returns 1 for error, 0 for success

    private:
		char* name; //Players custom name
		int health; //Players current health lvl
		int card_choice; //holds int to represent current card chioce, 1) attack, 2) defense, 3) heal
		lll_node* attack_head;
		cll_node* defense_rear;
		vector<heal_card> heal_cards; 
};


#endif // PLAYER_H
