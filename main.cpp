//main.cpp
//Drake Wheeler
//6/27/2024
//This file holds the main function. This is used to organize the program at the highest level. It is very simple and
//straight forward. This program runs a two-player card game. Each round, each player selects one card, either an attack, 
//defense, or heal card. Then the cards are played against each other. Based on the results of that round each player's
//health is affected. The game continues until on player's health goes below zero and then the other player has won. The
//program gives players more detailed instructions when it is played. 

#include "referee.h"

int main()
{
	referee game; //Creates a referee object
	int round_num = 0; //Used to keep track of what round it is to alternate between players who picks their card first
	int winner = 0; //Used in a while loop and to pass into a function to indicate which player won the game

	game.intro(); //Tells players the rules
	game.setup_players(); //Get player's name from users

	while(!winner) //While no one has won
	{
		game.prepare(round_num); //Get each player's card choice
		game.battle_ground(); //Play the cards against each other, update player's health
		winner = game.winner_check(); //Check is anyone won

		++round_num; //Increment the round number
	}

	game.results(winner); //Displays winning results to the users

    return 1;
}



