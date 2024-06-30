
#include "referee.h"

int main()
{
	referee game;
	int round_num = 0;

	game.intro();
	game.setup_players();

	game.prepare(round_num);


    return 0;
}



