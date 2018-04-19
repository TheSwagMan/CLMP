#include "monopoly.h"

int main(void)
{
    char buffer[100];
    int i;

    // creating board
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    // setting up saces
    board->cases = CASES;

    // set number of players
    printf("Combien de joueurs ? : ");
    fgets(buffer, sizeof(buffer), stdin);
    
    board->player_number = atoi(buffer);
    if (!(board->players = (player_t**)malloc(sizeof(player_t*) * board->player_number)))
        exit(-1);

    // creating a player
    for (i = 0; i < board->player_number; i++)
    {
        player_t *p;
        if (!(p = (player_t *)malloc(sizeof(player_t))))
            exit(-1);
        printf("Nom du joueur %d : ", i);
        if(!(fgets(buffer, sizeof(buffer), stdin)))
            exit(-2);
       buffer[strlen(buffer) - 1] = '\0';

        // default player settings
        p->money = 100;
        p->name = (char *)buffer;
        p->position = 0;
        board->players[i] = p;
    }
    printf("-\n");
    // displaying board for debug
    display_board(board);
    return 0;
}
