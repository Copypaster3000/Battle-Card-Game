//cll_node.cpp
//Drake Wheeler
//6/27/2024
//This file holds the functions for the cll_node class, this class acts as a node in a cll and each node is also
//a defense card, its parent class is defense_card which holds the card stats. The functions dealing with cards being 
//used in battle always use the card at the front of the cll, that is the card that is also deleted after being played. 
//Recursion is used to create the cll.

#include "cll_node.h"


//default constructor, sets card attributes at half power
cll_node::cll_node(void) : defense_card("Defense Card", 190, 1, 62), next(nullptr)
{}


//constructor, sets card attributes to values passed in
cll_node::cll_node(const string & name, int str, int tp, int hl) : defense_card("Defense Card", str, tp, hl), next(nullptr)
{}


//destructor
cll_node::~cll_node(void)
{
	delete next;
}


//creates cll of defense cards the size num nodes recursivley
int cll_node::create_cll(cll_node* & rear, int num_nodes)
{
	if(rear) return 0; //Return error if there is already a cll at rear passed in

	if(!num_nodes) return 1; //Return success after num_nodes originally passed in is zero

	//Creates a new card/node with random stats
	rear = new cll_node("Defense Card", rand() % 375, rand() % 2 + 1, rand() % 125);

	//Recursively calls the funciton again, passing the this nodes next pointer as rear and decrements the num_nodes counter
	return create_cll(rear->next, --num_nodes); 
}


//displays card stats of front card, because they are in a cll
int cll_node::display(void) const
{
	if(!next || !next->name) return 0; //Return error if there is no card in front of cll or card does not have a name
									   
	//dispalys stats from card at front of cll
	cout << next->name << endl;
	cout << "Strength: " << next->strength << endl;
	cout << "Type: " << next->type << endl;
	cout << "Heal Strength: " << next->heal << endl;

	return 1; //success
}


//deletes card in front of cll
int cll_node::next_card(cll_node* & rear)
{
	if(!rear) return 0; //Returns 0 for error if there is no node at rear passed in
						
	cll_node* temp = rear->next->next; //Holds onto next front of cll
	rear->next->next = nullptr; //sets node being deleted next ptr to null so the destructor doesn't delete the next node
	delete rear->next; //Deletes old front of cll
	rear->next = temp; //Sets rear->next to new front of cll

	return 1; //returns success
}


//return damage done to defending player healh, based on defense card in front of cll
int cll_node::defense(const lll_node & attack_card)
{
	return this->next->defend(attack_card); //Returns damage base on card at the front of cll
}


//Returns heal lvl of defense card played
int cll_node::heal_up(void)
{
	return next->heal_me(); //returns heal strength from card at front of cll
}

