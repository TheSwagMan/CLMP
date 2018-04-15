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

case_t CASES[] = {
    {(char *)"Belleville", 0, TYPE_STREET, -1, 100, 100},
    {(char *)"Lecourbe", 0, TYPE_STREET, -1, 100, 100},
    {(char *)"Vaugirard", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Courcelles", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"La Vilette", 2, TYPE_STREET, -1, 100, 100},
    {(char *)"Neuilly", 2, TYPE_STREET, -1, 100, 100},
    {(char *)"Mozart", 3, TYPE_STREET, -1, 100, 100},
    {(char *)"Saint-Michel", 3, TYPE_STREET, -1, 100, 100},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 100, 100},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 100, 100},
    {(char *)"Saint-Honore", 5, TYPE_STREET, -1, 100, 100},
    {(char *)"La Bourse", 5, TYPE_STREET, -1, 100, 100},
    {(char *)"Breteuil", 6, TYPE_STREET, -1, 100, 100},
    {(char *)"Foch", 6, TYPE_STREET, -1, 100, 100},
    {(char *)"Champs-Elysees", 7, TYPE_STREET, -1, 100, 100},
    {(char *)"La Paix", 7, TYPE_STREET, -1, 100, 100},
    
    {(char *)"Belleville", 0, TYPE_STREET, -1, 100, 100},
    {(char *)"Lecourbe", 0, TYPE_STREET, -1, 100, 100},
    {(char *)"Vaugirard", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"Courcelles", 1, TYPE_STREET, -1, 100, 100},
    {(char *)"La Vilette", 2, TYPE_STREET, -1, 100, 100},
    {(char *)"Neuilly", 2, TYPE_STREET, -1, 100, 100},
    {(char *)"Mozart", 3, TYPE_STREET, -1, 100, 100},
    {(char *)"Saint-Michel", 3, TYPE_STREET, -1, 100, 100},
    {(char *)"Matignon", 4, TYPE_STREET, -1, 100, 100},
    {(char *)"Malesherbes", 4, TYPE_STREET, -1, 100, 100},
    {(char *)"Saint-Honore", 5, TYPE_STREET, -1, 100, 100},
    {(char *)"La Bourse", 5, TYPE_STREET, -1, 100, 100},
    {(char *)"Breteuil", 6, TYPE_STREET, -1, 100, 100},
    {(char *)"Foch", 6, TYPE_STREET, -1, 100, 100},
    {(char *)"Champs-Elysees", 7, TYPE_STREET, -1, 100, 100},
    {(char *)"La Paix", 7, TYPE_STREET, -1, 100, 100},
};

void    display_board(board_t *board);
char    *generate_empty_grid(int size);

#endif /* _GUI_H_ */
