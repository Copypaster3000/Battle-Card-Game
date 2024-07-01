//referee.h
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is the header file for the referee class

#include "player.h"


class referee
{
	public:
		referee(void);
		~referee(void);
		void intro(void); //Explains the game to the players
		void setup_players(void); //Sets up players with their names
		void prepare(int round_num); //Shows players their health and lets them select their cards, pass in round number to alternate who picks card first
		void battle_ground(void); //Facilitates battle, updates players health based on cards played

	private:
		player* player1; //One player object for each player
		player* player2;
};

