#include "monopoly.h"

int main(void)
{
    board_t  *board;
    board = (board_t *)malloc(sizeof(board_t));
    board->cases = CASES;
    player_t *p1 = (player_t *)malloc(sizeof(player_t));
    p1->money = 100;
    p1->name = (char *)"Thomas";
    p1->position = 3;
    board->players = (player_t **)malloc(sizeof(player_t *));
    board->players[0] = p1;
    board->player_number = 1;
    display_board(board);
    return 0;
}
