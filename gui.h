#ifndef _GUI_H_
# define _GUI_H_ 

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "structures.h"
# include "utils.h"

# define X_CHAR     'o'
# define V_CHAR     '|'
# define H_CHAR     '-'
# define N_CHAR     ' '

# define V_SIZE     4
# define H_SIZE     22
# define GRID_SIZE  9
# define CASE_COUNT 4 * (GRID_SIZE - 1)

void    display_board(board_t *board);
char    *generate_empty_grid(int size);

#endif /* _GUI_H_ */
