//lll_node.h
//Drake Wheeler
//6/27/2024
//This is the header file for the lll_card which is derived from the attack_card class which is derived from the card class.
//This class will be used as the node for a linear linked list which will hold attack cards. This class enables clients to 
//create a linear linked list of attack cards, delete the front of the lll and set the next node to head, removing the last
//played card from the data structure, and count the number of nodes left in the lll. 

#ifndef LLL_NODE_H
#define LLL_NODE_H

#include "attack_card.h"


class lll_node : public attack_card
{
	public:
		lll_node(void); //default constructor
		lll_node(const string & strng, int str, int typ); //constructor with arguements to set card strength and type and name
		~lll_node(void); //destructor
		int create_lll(lll_node* & head, int num_nodes); //Pass in the head pointer to this funciton to create a lll of random cards the size of int passed in, returns 1 for success, 0 for error
		int next_card(lll_node* & head); //Deletes head card and makes next card head passed in head, return 1 for success, 0 for error
		int cards_left(lll_node* head); //returns the number of cards left in the lll after the node passed in

	private:
		lll_node* next; //points to the next node in linear linked list


};


#endif // LLL_NODE_H
