#ifndef _CARD_EFFECTS_H_
# define _CARD_EFFECTS_H_

# include "structures.h"
# include "constants.h"
# include "utils.h"

void    card_prison(board_t *board, int owner, int value);
void    card_prize(board_t *board, int owner, int value);
void    card_replay(board_t *board, int owner, int value);
void    card_station(board_t *board, int owner, int value);
void    card_street_station(board_t *board, int owner, int value);
void    card_destroy(board_t *board, int owner, int value);
void    card_tax(board_t *board, int owner, int value);
void    card_escape(board_t *board, int owner, int value);
void    card_free(board_t *board, int owner, int value);
void    card_double(board_t *board, int owner, int value);
void    card_parc(board_t *board, int owner, int value);

#endif /* _CARD_EFFECTS_H_ */
