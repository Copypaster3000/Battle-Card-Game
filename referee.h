//referee.h
//Drake Wheeler
//6/27/2024
//This is the header file for the referee class. This entire game can be run through the functions in this class.
//This class is used to explain the game, set up players with their custom names, allow them to choose their cards
//each turn and battle against each other and declare the winner when the game is over. 
//

#include "player.h"


class referee
{
	public:
		referee(void); //Constructor
		~referee(void); //Destructor
		void intro(void) const; //Explains the game to the players
		void setup_players(void); //Sets up players with their names
		void prepare(int round_num); //Shows players their health and lets them select their cards, pass in round number to alternate who picks card first
		void battle_ground(void); //Facilitates battle, updates players health based on cards played
		int winner_check(void) const; //returns 0 if no one is dead, 3 if both players are dead, 1 if player 1 is dead, 2 if player 2 is dead
		void results(int winner) const; //Pass in winner int from winner check, displays ending to users


	private:
		player* player1; //One player object for each player
		player* player2;
};

