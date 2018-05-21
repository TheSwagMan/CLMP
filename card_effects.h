#ifndef _CARD_EFFECTS_H_
# define _CARD_EFFECTS_H_

# include "structures.h"
# include "constants.h"
# include "utils.h"

int    card_prison(board_t *board, int owner, int value);
int    card_prize(board_t *board, int owner, int value);
int    card_replay(board_t *board, int owner, int value);
int    card_station(board_t *board, int owner, int value);
int    card_street_station(board_t *board, int owner, int value);
int    card_destroy(board_t *board, int owner, int value);
int    card_tax(board_t *board, int owner, int value);
int    card_escape(board_t *board, int owner, int value);
int    card_free(board_t *board, int owner, int value);
int    card_double(board_t *board, int owner, int value);
int    card_parc(board_t *board, int owner, int value);

#endif /* _CARD_EFFECTS_H_ */
