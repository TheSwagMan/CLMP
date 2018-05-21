#include "card_effects.h"

int    card_prison(board_t *board, int owner, int value)
{
    (void)value;
    player_t *player = board->players[owner];
    player->position = 8;
    player->prison_for = TIME_PRISON;
    return (0);
}

int    card_prize(board_t *board, int owner, int value)
{
    player_t *player = board->players[owner];
    player->money += value;
    return (0);
}

int card_replay(board_t *board, int owner, int value)
{
    (void)value;
    (void)board;
    (void)owner;
    return (1);
}


int card_station(board_t *board, int owner, int value)
{
    player_t *player = board->players[owner];
    (void)value;
    int t[] = {4, 11, 21, 27};
    int c = randint(0, sizeof(t));
    player->position  = t[c];
    return (0);
}

int card_street_station(board_t *board, int owner, int value)
{
    player_t *player = board->players[owner];
    (void)value;
    int t[] = {3, 4, 6, 8, 11, 13, 16, 18, 21, 24, 27, 28, 30};
    int c = randint(0, sizeof(t));
    player->position  = t[c];
    return (0);
}

int card_destroy(board_t *board, int owner, int value)
{
    (void)owner;
    (void)value;
    int c;
    do {
        c = randint(0, CASE_COUNT);
    } while ((board->cases[c].type != TYPE_STREET
            || board->cases[c].type != TYPE_STATION)
            && board->cases[c].owner == -1);
    board->cases[c].owner = -1;
    return (0);
}

int card_tax(board_t *board, int owner, int value)
{
    (void)value;
    player_t *player = board->players[owner];
    player->position = 3;
    return (0);
}

int card_parc(board_t *board, int owner, int value)
{
    (void)value;
    player_t *player = board->players[owner];
    player->position = 16;
    return (0);
}

int card_escape(board_t *board, int owner, int value)
{
    (void)value;
    player_t *player = board->players[owner];
    player->prison_for = 0;
    return (0);
}


