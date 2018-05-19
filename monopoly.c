#include "monopoly.h"


void buy_case(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number]; 

    // enough money ?
    if (player->money >= board->cases[case_number].initial_price)
    {
        if (ask((char *)"Acheter ?"))
        {
            player->money -= board->cases[case_number].initial_price;
            board->cases[case_number].owner = player_number;
        }
    }

}

void pay_rent(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number]; 

    // can player pay ?
    if (player->money >= board->cases[case_number].price)
    {
        player->money -= board->cases[case_number].price;
        board->players[board->cases[case_number].owner]->money += board->cases[case_number].price;
    }
    else
    {
        // TODO: HANDLE RESELL
    }
}

void handle_street_station(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number]; 

    (void)player;
    // case free
    if (board->cases[case_number].owner == -1)
        buy_case(board);
    else
        pay_rent(board);
    // TODO: FIX PRICE
    /* 
       int price=0;
       if (board->players[player_number]->money >= price && ask((char *)"Racheter ?"))
       {
       board->players[player_number]->money -= price;
       board->players[board->cases[case_number].owner]->money += price;
       board->cases->owner = player_number;
       }
       */
}

void apply_case(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number]; 

    switch (board->cases[case_number].type)
    {
        case TYPE_STREET:
            handle_street_station(board);
            break;
        case TYPE_GOPRISON:
            player->position = 8;
            player->prison_for = TIME_PRISON;
            break;
        case TYPE_STATION:
            handle_street_station(board);
            break;
        case TYPE_TAX:
            player->money -= MONEY_TAX;
            board->jackpot += MONEY_TAX;
            break;
        case TYPE_PARK:
            player->money += board->jackpot; //gagne l'argent stocké dans la CAGNOTTE
            board->jackpot = 0;
            break;
        default:
            break;
    }
}


int main(void)
{
    char buffer[100];
    int i;

    // seeding random algorithm
    srand(time(NULL));
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
    // creating players
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
        p->money = MONEY_START;
        if (!(p->name = (char *)malloc((strlen(buffer) + 1) * sizeof(char))))
            exit(-1);
        if (!(strcpy(p->name, buffer)))
            exit(-3);
        p->position = 0;
        board->players[i] = p;
    }
    //debut de partie
    board->current_player = 0;
    board->game_running = 1;
    while (board->game_running)
    {
        display_board(board);
        printf("Au tour de %s !", board->players[board->current_player]->name);
        fgets(buffer, sizeof(buffer), stdin);
        int lancer1 = dice();
        int lancer2 = dice();
        printf("%s lance les des : %d et %d (%d).\n", board->players[board->current_player]->name, lancer1, lancer2, lancer1 + lancer2);
        // player is not in prison
        if (board->players[board->current_player]->prison_for == 0)
        {
            // move player and reward for turn
            board->players[board->current_player]->position += lancer1 + lancer2;
            if (board->players[board->current_player]->position >= CASE_COUNT)
            {
                board->players[board->current_player]->position = board->players[board->current_player]->position % CASE_COUNT;
                board->players[board->current_player]->money += MONEY_TURN_REWARD;
            }
        }
        else
        {
            board->players[board->current_player]->prison_for--;
            if (lancer1 == lancer2)
            {
                printf("%s sort de prison !", board->players[board->current_player]->name);
                board->players[board->current_player]->prison_for = 0;
            }
        }
        display_board(board);
        // apply case effect
        apply_case(board);
        // next player
        board->current_player++;
        // all player played -> new round
        if (board->current_player >= board->player_number)
        {
            board->current_player = 0;
        }
    }
    return 0;
}

