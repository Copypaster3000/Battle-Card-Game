//lll_node.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file for the cll_node class. This class will act as a node in a linear linked list which will hold attack cards

#include "lll_node.h"


//defualt constructor
lll_node::lll_node(void) : attack_card("Attack Card", 250, 1), next(nullptr)
{}

//constructor. The initilzation list calls it's parent class's constructor to set the strength and attack type for the attack card
lll_node::lll_node(const char* strng, int str, int typ) : attack_card(strng, str, typ), next(nullptr)
{
}


//destructor
lll_node::~lll_node(void)
{}


//lll creator
int lll_node::create_lll(lll_node* & head, int num_nodes)
{
	if(num_nodes == 0) return 0;

	//Creates new node, passes in random number below 500 for strength lvl, and a 1 or 2 for attack type 
	head = new lll_node("Attack Card", rand() % 500, (rand() % 2) + 1);

	//recursively calls the function to add another card to the lll, adds one to num of nodes for stop case
	return create_lll(head->next, --num_nodes);
}

