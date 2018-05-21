#include "card_effects.h"

void    card_prison(board_t *board, int owner, int value)
{
    (void)value;
    player_t *player = board->players[owner];
    player->position = 8;
    player->prison_for = TIME_PRISON;
}

void    card_prize(board_t *board, int owner, int value)
{ 
    player_t *player = board->players[owner];
    player->money += value;
}
