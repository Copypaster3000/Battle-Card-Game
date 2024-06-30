//lll_node.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the lll_card which is dervied from the attack_card class which is derived from the card class.
//This class will be used as the node for a linear linked list which will hold attack cards.

#ifndef LLL_NODE_H
#define LLL_NODE_H

#include "attack_card.h"


class lll_node : public attack_card
{
	public:
		lll_node(void); //default constructor
		lll_node(char* strng, int str, int typ); //constructor with arguements to set card strength and type and name
		~lll_node(void);
		int create_lll(lll_node* & head, int num_nodes); //Pass in the head pointer to this funciton to create a lll of random cards

	private:
		lll_node* next;
};


#endif // LLL_NODE_H
