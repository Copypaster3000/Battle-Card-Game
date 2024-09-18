//lll_node.cpp
//Drake Wheeler
//6/27/2024
//This is the file for the lll_node class. This class acts as a node in a linear linked list which will hold attack cards.
//Recursion is used here to create the lll of attack cards. To delete and a card at the front of the lll and set head to 
//the next card pointers are used. Recursion is also used to count the nodes left in the lll.

#include "lll_node.h"


//default constructor
lll_node::lll_node(void) : attack_card("Attack Card", 250, 1), next(nullptr)
{}

//constructor. The initialization list calls its parent class's constructor to set the strength and attack type for the attack card
lll_node::lll_node(const string & strng, int str, int typ) : attack_card(strng, str, typ), next(nullptr)
{
}


//destructor
lll_node::~lll_node(void)
{
	if(next) delete next; //If next is pointing to something, delete it
}


//lll creator
int lll_node::create_lll(lll_node* & head, int num_nodes)
{
	if(head) return 0; //Returns failure if there is already something at head

	if(num_nodes == 0) return 1; //Returns success after creating all nodes

	//Creates new node, passes in random number below 500 for strength lvl, and a 1 or 2 for attack type 
	head = new lll_node("Attack Card", rand() % 500, (rand() % 2) + 1);

	//recursively calls the function to add another card to the lll, adds one to num of nodes for stop case
	return create_lll(head->next, --num_nodes);
}


//pass in lll_node* head of attack cards
int lll_node::next_card(lll_node* & head)
{
	if(!head) return 0; //returns error

	lll_node* temp = head; //Holds onto head
	head = head->next; //Sets head to next card
	temp->next = nullptr; //Sets node being deleted next ptr to null so that the destructor doesn't delete the node pointed to by next
	delete temp; //deletes old head

	return 1; //returns success
}


//pass in node to return nodes left in lll after it	
int lll_node::cards_left(lll_node* head)
{
	if(!head) return 0; //If there is no node at pointer return 0 for no node counted and end recursion

	return 1 + cards_left(head->next); //Return 1 to count node and call function with next node
}

