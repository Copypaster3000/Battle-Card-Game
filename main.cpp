
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

		++round_num;
	}




    return 0;
}



