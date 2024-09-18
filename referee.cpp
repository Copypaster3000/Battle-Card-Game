//referee.cpp
//Drake Wheeler
//6/27/2024
//This file holds the function definitions for the referee class. This class organizes and runs the game.
//It is mainly used to call and organize functions from the player class. 

#include "referee.h"


//Constructor
referee::referee(void) : player1(nullptr), player2(nullptr)
{}


//Destructor
referee::~referee(void)
{
	delete player1; 
	delete player2;
}


//This function explains the game
void referee::intro(void) const
{
	cout << "\nWelcome to a game of battle... to the death!\n" << endl;
	cout << "This is a two-player card game. Each player starts with 1000 health." << endl;
	cout << "The first player to reduce their opponent's health to zero wins. Each" << endl;
	cout << "player is dealt three decks of cards at the beginning of the game." << endl;
	cout << "There are attack cards, defense cards, and heal cards. Each round both" << endl;
	cout << "players will select one card from a deck of their choice. The cards will" << endl;
	cout << "then be played against each other and the results will impact each player's" << endl;
	cout << "health. Attack cards have a strength level of 500 to 0. The level of strength is the" << endl;
	cout << "amount of damage that can be done to the enemy's health. However, there are two" << endl;
	cout << "different types of attacks. If the enemy chooses a defense card that corresponds" << endl;
	cout << "to the type of attack card you have, your attack will be reduced in strength by" << endl;
	cout << "the strength of the defense card. If the defense card does not defend the attack" << endl;
	cout << "type, all of the attack's damage will be subtracted from the enemy's health." << endl;
	cout << "Defense cards have between 375 to 0 strength. Again, if the defense type does" << endl;
	cout << "not block the attack the damage will still be done. There are two types of attack" << endl;
	cout << "and defense cards. Defense cards also have between 150 to 0 heal strength. Regardless" << endl;
	cout << "of the other player's card, the heal strength will be added to your health." << endl;
	cout << "Lastly there are heal cards. Heal cards have strength from 300 to 200, which increases your health" << endl;
	cout << "each time you play it. But they do not defend against attacks or do any damage to your opponent." << endl;
	cout << "The stats for all the cards are randomly generated to be somewhere within their listed ranges." << endl;
	cout << "The player that chooses their card first will alternate each round." << endl;
	cout << "Each player is not allowed to look at the type of card the other player chooses before the battle!\n" << endl;
	cout << "Good luck and may the best player win!\n" << endl;

	return;
}


//Creates player objects with players custom names
void referee::setup_players(void)
{
	string name1, name2; //Creates string to temporarily hold user's input names

	//Gets names from user's and displays what they entered
	cout << "Player one, enter what you would like to be called for the game: ";
	getline(cin, name1);
	cout << "Player one, hence forth you shall be called \"" << name1 << "\"." << endl;
	cout << "\nPlayer two, enter what you would like to be called for the game: ";
	getline(cin, name2);
	cout << "Player two, hence forth you shall be called \"" << name2 << "\"." << endl;

	//Creates player objects with their custom names and a different offset int so the cards randomly created are different
	player1 = new player(name1, 1);
	player2 = new player(name2, 2);

	return;
}


//Pepares for battle, pass in what round it is to alternate which player picks card first
//Shows player's health, gets playes card choice, displays players cards
void referee::prepare(int round)
{
	//Displays player's health, displays error message if there is an error
	cout << endl;
	if(!player1->display_health()) cout << "\nError displaying player1's name and health." << endl;
	if(!player2->display_health()) cout << "\nError displaying player2's namd and health." << endl;
	cout << endl;

	//Alternates which player chooses card first, prompts user to select again if input is invalid
	if(round % 2 == 0) 
	{
		//Get's player's card choice, repeats while player input is invalid
		while(!player2->get_card_choice()) cout << "ERROR! Invalid input. Enter an integer from the menu.\n" << endl;
		while(!player1->get_card_choice()) cout << "ERROR! Invalid input. Enter an integer from the menu.\n" << endl;
	}
	else 
	{
		while(!player1->get_card_choice()) cout << "ERROR! Invalid input. Enter an integer from the menu.\n" << endl;
		while(!player2->get_card_choice()) cout << "ERROR! Invalid input. Enter an integer from the menu.\n" << endl;
	}

	//Displays player card choices, displays error message if there is an error
	if(player1->display_card()) cout << "Error displaying player1's card" << endl;
	if(player2->display_card()) cout << "Error displaying player2's card" << endl;

	return;
}


//Facilitate battle, update card decks, check for winner, update round num
void referee::battle_ground(void)
{
	//Player's cards are played against each other and their health is updated
	if(!player1->battle(player2)) cout << "\nError during battle." << endl; 

	//Updates each player's deck after having played a card, removes card last played from data structure
	if(!player1->update_decks()) cout << "\nError updating player1's deck." << endl; 
	if(!player2->update_decks()) cout << "\nError updating player2's deck." << endl;

	return;
}


//checks if the game is over
int referee::winner_check(void) const
{
	if(player1->dead() && player2->dead()) return 3; //Returns three is there is a tie

	if(player1->dead()) return 1; //Returns 1 if player1 died

	if(player2->dead()) return 2; //Returns 2 if player2 died

	return 0; //No one died
}


//end of game
void referee::results(int winner) const
{
	//Based on int passed in displays correct winning message
	if(winner == 3)
	{
		cout << "\n**********************************" << endl;
    	cout << "*                                *" << endl;
    	cout << "*          IT'S A TIE!           *" << endl;
    	cout << "*                                *" << endl;
    	cout << "**********************************" << endl;
    	cout << "*                                *" << endl;
    	cout << "*       A RARE OCCURRENCE!       *" << endl;
    	cout << "*     BOTH PLAYERS FOUGHT        *" << endl;
    	cout << "*      VALIANTLY TO DEATH!       *" << endl;
		cout << "*   YOU WERE EACH KILLED FROM    *" << endl;
		cout << "*   YOUR OPPENENTS LAST ATTACK!  *" << endl;
    	cout << "*                                *" << endl;
    	cout << "**********************************" << endl;
    	cout << "\nThe game is now over.\n" << endl;
	}
	else if(winner == 2) 
	{
		//Displays winning message for player, and error message if winning player is actually dead
		if(!player1->won()) cout << "\nError, 'winning' player's health is not above 0." << endl;
	}
	else if(winner == 1) 
	{
		if(!player2->won()) cout << "\nError, 'winning' player's health is not above 0." << endl;
	}

	return;
}











