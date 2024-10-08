//cll_node.h
//Drake Wheeler
//6/27/2024
//This is the header file for the cll_node class which is derived from the defense_card class which is a derivation of the card class.
//This class is used as a node in a circular linked list that will hold defense cards. This class enables clients to create a cll of
//random defense cards, delete the front node from the cll, display the defense card's stats, facilitate defending against an attack card
//and healing a player's health based on the defense card's stats

#ifndef CLL_NODE_H
#define CLL_NODE_H

#include "defense_card.h"


class cll_node : public defense_card
{
	public:
		cll_node(void); //Sets card attributes to half power
		cll_node(const string & name, int str, int tp, int hl); //Sets card attributes to values passed in
		~cll_node(void); //Destructor
		int create_cll(cll_node* & rear, int num_nodes); //Creates cll of 100 defense cards with rear pointer as the pointer passed in, returns 1 for success, 0 for error
		int next_card(cll_node* & rear); //Deletes card on front of cll (removes it from deck), returns 1 for success, 0 for error
		int display(void) const; //Displays card on front of cll, returns 1 for success, 0 for error
		int defense(const lll_node & attack_card); //Pass in lll_node object of attack card, so dereference it when passing in, returns damage done to defending player's health as a positive number
		int heal_up(void); //Returns heal lvl of defense card at front of cll to be added to player's health

	

	private:
		cll_node* next; //pointer to next node in cll
};


#endif // CLL_NODE_H
