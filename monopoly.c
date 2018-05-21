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

int apply_card(board_t *board, int player_id, card_t *card)
{
    return card->effect(board, player_id, card->value); 
}

int apply_case(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number]; 
    card_t *card;
    switch (board->cases[case_number].type)
    {
        case TYPE_STREET:
            handle_street_station(board);
            break;
        case TYPE_GOPRISON:
            player->position = 8;
            player->prison_for = TIME_PRISON;
            break;
        case TYPE_PRISON:
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
        case TYPE_LUCKY:
            card = &CARDS[SHUFFLED_CARDS[board->current_card]];
            display_card(card);
            getchar();
            return apply_card(board, player_number, card);
            break;
        default:
            break;
    }
    return (0);
}

void    shuffle_cards(void)
{
    int i, t, j;
    for (i = 0; i < (int)CARD_COUNT; i++)
    {
        SHUFFLED_CARDS[i] = i; 
    }
    for (i = 0; i < (int)CARD_COUNT; i++)
    {
        j = rand() % CARD_COUNT;
        t = SHUFFLED_CARDS[j];
        SHUFFLED_CARDS[j] = SHUFFLED_CARDS[i];
        SHUFFLED_CARDS[i] = t;
    }
}

int main(void)
{
    char buffer[100];
    int i, de1, de2, replay;

    // seeding random algorithm
    srand(time(NULL));
    // shuffling cards
    shuffle_cards();
    // creating board
    board_t  *board;
    if (!(board = (board_t *)malloc(sizeof(board_t))))
        exit(-1);
    // setting up saces
    board->cases = CASES;
    // set number of players
    do {
        printf("Combien de joueurs ? : ");
        fgets(buffer, sizeof(buffer), stdin);
        board->player_number = atoi(buffer);
    } while (board->player_number < 2);
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
    replay = 0;
    while (board->game_running)
    {
        de1= dice();
        de2 = dice();
        display_board(board);
        printf("Au tour de %s !", board->players[board->current_player]->name);
        getchar();
        printf("%s lance les des : %d et %d (%d).\n", board->players[board->current_player]->name, de1, de2, de1 + de2);
        // player is not in prison
        if (board->players[board->current_player]->prison_for == 0)
        {
            // if double -> replay
            if (de1 == de2)
                replay += 1;
            // move player and reward for turn
            board->players[board->current_player]->position += de1 + de2;
            if (board->players[board->current_player]->position >= CASE_COUNT)
            {
                board->players[board->current_player]->position = board->players[board->current_player]->position % CASE_COUNT;
                board->players[board->current_player]->money += MONEY_TURN_REWARD;
            }
            // apply case effect
            replay += apply_case(board);
        }
        else
        {
            board->players[board->current_player]->prison_for--;
            if (de1 == de2)
            {
                printf("%s sort de prison !", board->players[board->current_player]->name);
                board->players[board->current_player]->prison_for = 0;
            }
        }
        display_board(board);
        if (!replay)
        {
            // next player
            board->current_player++;
            // all player played -> new round
            if (board->current_player >= board->player_number)
            {
                board->current_player = 0;
            }
        }
        replay = 0;
    }
    return 0;
}

