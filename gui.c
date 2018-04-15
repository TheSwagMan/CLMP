#include "gui.h"

void    display_board(board_t *board)
{
    (void)board;

}

char    *generate_empty_grid(int size)
{
    char *grid;
    int x, y, i, j, index;

    y = (CASE_SIZE + 1) * size + 1;
    x = y + 1;
    grid = (char *)malloc(sizeof(char) * y * 2 * x);
    for (i = 0; i < y * x * 2; i++)
        grid[i] = ' ';
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            index = (i * x + j) * 2 - 2;
            if (j == x - 1)
                grid[index] = '\n';
            // drawing grid
            else if (i == 0 || i == y - 1 || i == CASE_SIZE + 1
                    || i == y - CASE_SIZE - 2 || j == 0 || j == x - 2
                    )
                grid[index] = '*';
        }
    }
    return (grid);
}
