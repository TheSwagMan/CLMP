#include "monopoly.h"

int main(void)
{
	int number = 0;
	char name[100];
    int i;

    // creating board
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    // setting up saces
    board->cases = CASES;

    // set number of players
	printf("Combien de joueurs ? : ");
	scanf("&s",*number);

    board->player_number = number;

    if (!(board->players = (player_t**)malloc(sizeof(player_t*) * board->player_number)))
        exit(-1);

    //// creating a player
	for (i = 0 ; i < number ; i++)
    {
        player_t *p1;
        fgets(name,100,stdin);
        if (!(p1 = (player_t *)malloc(sizeof(player_t))))
            exit(-1);
        p1->money = 100;
        p1->name = (char *)name;
        p1->position = 3;
        board->players[i]=p1;
    }


    // adding player to board
    board->players[0] = p1;

    // displaying board for debug
    display_board(board);
    return 0;
}
