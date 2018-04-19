#include "monopoly.h"

int main(void)
{
    // creating board
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    // setting up saces
    board->cases = CASES;
   
    // set number of players
    board->player_number = 1;
    
    //// creating a player
    player_t *p1;
    if (!(p1 = (player_t *)malloc(sizeof(player_t))))
        exit(-1);
    p1->money = 100;
    p1->name = (char *)"Thomas";
    p1->position = 3;

    // adding player to board
    board->players[0] = p1;

    // displaying board for debug
    display_board(board);
    return 0;
}
