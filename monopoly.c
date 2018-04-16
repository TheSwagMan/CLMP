#include "monopoly.h"

int main(void)
{
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    board->cases = CASES;
    board->cases[0].owner = 0;
    board->cases[0].price = 1000;
    player_t *p1;
    if (!(p1 = (player_t *)malloc(sizeof(player_t))))
        exit(-1);
    p1->money = 100;
    p1->name = (char *)"Thomas";
    p1->position = 3;
    player_t *p2;
    if (!(p2 = (player_t *)malloc(sizeof(player_t))))
        exit(-1);
    p2->money = 500;
    p2->name = (char *)"L'autre";
    p2->position = 10;
    if (!(board->players = (player_t **)malloc(sizeof(player_t *) * 2)))
        exit(-1);
    board->players[0] = p1;
    board->players[1] = p2;
    board->player_number = 2;
    display_board(board);
    return 0;
}
