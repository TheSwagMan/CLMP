#ifndef _GUI_H_
# define _GUI_H_ 

# include <stdio.h>
# include <stdlib.h>
# include "structures.h"
# include "constants.h"

void    display_board(board_t *board);
char    *generate_empty_grid(int size);

#endif /* _GUI_H_ */
