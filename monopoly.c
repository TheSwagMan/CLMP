#include "monopoly.h"

int main(void)
{
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    board->cases = CASES;
    player_t *p1;
    if (!(p1 = (player_t *)malloc(sizeof(player_t))))
        exit(-1);
    p1->money = 100;
    p1->name = (char *)"Thomas";
    p1->position = 3;
    if (!(board->players = (player_t **)malloc(sizeof(player_t *))))
        exit(-1);
    board->players[0] = p1;
    board->player_number = 1;
    display_board(board);
    return 0;
}
