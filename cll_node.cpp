//cll_node.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file holds the function for the cll_node class, this class acts as a node in a cll and manages it

#include "cll_node.h"

//default constructor, sets card attributes at half power
cll_node::cll_node(void) : defense_card("Defense Card", 190, 1, 62), next(nullptr)
{}


//constructor, sets card attributes to values passed in
cll_node::cll_node(char* name, int str, int tp, int hl) : defense_card("Defense Card", str, tp, hl), next(nullptr)
{}


//destructor
cll_node::~cll_node(void)
{}


//creates cll of 100 attack cards
int cll_node::create_cll(cll_node* & rear, int num_nodes)
{
	if(!num_nodes) return 0; //Return success after num_nodes originally passed in is zero

	//Creates a new card/node with random stats
	rear = new cll_node("Defense Card", rand() % 375, rand() % 2 + 1, rand() % 125);

	//Recursively calls the funciton again, passing the this nodes next pointer as rear and decrements the num_nodes counter
	return create_cll(rear->next, --num_nodes); 
}
