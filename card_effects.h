#ifndef _CARD_EFFECTS_H_
# define _CARD_EFFECTS_H_

# include "structures.h"
# include "constants.h"

void    card_prison(board_t *board, int owner, int value);
void    card_prize(board_t *board, int owner, int value);

#endif /* _CARD_EFFECTS_H_ */
