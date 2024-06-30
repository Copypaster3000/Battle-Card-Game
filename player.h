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
using namespace std;

class player
{
    public:
        player(void);
		player(char* nm);
        ~player(void);
        int update_health(int impact); //Updates players health based off results from last battle

    private:
		char* name; 
		int health;
		lll_node* attack_head;
		cll_node* defense_rear;
		vector<heal_card> heal_cards; 
};


#endif // PLAYER_H
