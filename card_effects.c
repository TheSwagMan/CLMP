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
void card_replay(board_t *board, int owner, int value)
{
  player_t *player = board->players[owner];
  
}


void card_station(board_t *board, int owner, int value)
{
  player_t *player = board->players[owner];
  int t[] = {4, 11, 21, 27};
  int c = frand_2(0, sizeof(t));
  palyer->position  = t[c];
}

void card_street_station(board_t *board, int owner, int value)
{
  player_t *player = board->players[owner];
  int t[] = {3, 4, 6, 8, 11, 13, 16, 18, 21, 24, 27, 28, 30};
  int c = frand_2(0, sizeof(t));
  palyer->position  = t[c];
}

void card_restart(board_t *board, int owner, int value)
{
  int c;
do {
      c = frand_2(0, CASE_NUMBER);
  } while (board->cases[c].type != TYPE_STREET || board->cases[c].type != TYPE_STATION);
            board->cases[c].owner = -1;
}

void card_tax(board_t *board, int owner, int value)
{
  player_t *player = board->players[owner];
  player->position = 3;

}

void card_park(board_t *board, int owner, int value)
{
  player_t *player = board->players[owner];
  player->position = 16;

}

void card_escape(board_t *board, int owner, int value)
{
    player_t *player = board->players[owner];
    player->objets = 1
  }


  void card_free(board_t *board, int owner, int value)
  {
    player_t *player = board->players[owner];
    player->objets = 2;
  }


  void card_double(board_t *board, int owner, int value)
  {
    player_t *player = board->players[owner];
    player->objets = 3;
  }
