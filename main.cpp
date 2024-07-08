//main.cpp
//Drake Wheeler
//Karla Fant
//CS302
//Program 1
//6/27/2024
//This is file holds the main program

#include "referee.h"

int main()
{
	referee game;
	int round_num = 0;
	int winner = 0;

	game.intro();
	game.setup_players();

	while(!winner)
	{
		game.prepare(round_num);
		game.battle_ground();
		winner = game.winner_check();

		++round_num;
	}

	game.results(winner);

    return 0;
}



