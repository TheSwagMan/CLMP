#ifndef _GUI_H_
# define _GUI_H_ 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "structures.h"
# include "utils.h"
# include "constants.h"

void    display_board(board_t *board);
char    *generate_empty_grid(int size);
void    display_card(card_t *card);

#endif /* _GUI_H_ */
