#include "monopoly.h"


int is_won(board_t *board){
    int player_alive = 0;
    // counting alive players
    for (int i = 0; i < board->player_number; i++)
        if (board->players[i]->out == 0)
            player_alive++;
    if (player_alive == 1)
        return (1);
    int a = board->cases[4].owner;
    if (a == board->cases[11].owner
            && a == board->cases[21].owner
            && a == board->cases[27].owner
            && a >= 0)
        return (1);
    return (0);
}

void buy_case(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number];

    // enough money ?
    if (player->money >= board->cases[case_number].price)
    {
        if (ask((char *)"Acheter ?"))
        {
            player->money -= board->cases[case_number].price;
            board->cases[case_number].owner = player_number;
        }
    }
}

int resell_case(board_t *board, int money)
{
    int player_number = board->current_player;
    int owned_cases[CASE_COUNT] = {-1};
    int own_count = 0;
    int i, k;
    char buffer[10];
    int money_got = 0;

    while (money_got < money)
    {
        for (i = 0; i < CASE_COUNT; i++)
        {
            if (board->cases[i].owner == player_number)
                owned_cases[own_count++] = i;
        }
        if (own_count > 0)
        {
            printf("Sell (%d cases)\n", own_count);
            for (i = 0; i < own_count; i++)
            {
                printf("%i: %s", i, board->cases[owned_cases[i]].name);
                if (i != own_count - 1)
                    printf(", ");
            }
            printf("\n");
            fgets(buffer, sizeof(buffer), stdin);
            k = atoi(buffer);
            board->cases[k].owner = -1;
            board->players[player_number]->money += board->cases[k].price;
            money_got += board->cases[k].price;
        }
        else
            return (0);
    }
    return (1);
}

void pay_rent(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;
    player_t *player = board->players[player_number];

    int rent_price = 0.3 * board->cases[case_number].price;

    // can player pay ?
    if (player->money >= rent_price)
    {
        player->money -= rent_price;
        board->players[board->cases[case_number].owner]->money += rent_price;
    }
    else
    {
        if (!resell_case(board, player->money - rent_price))
            board->players[player_number]->out = 1;
        else
        {
            player->money -= rent_price;
        }
    }
}

void handle_street_station(board_t *board)
{
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;

    // case free
    if (board->cases[case_number].owner == -1)
    {
        buy_case(board);
        board->cases[case_number].price *= 1.5;
    }
    else
        pay_rent(board);
    display_board(board);
    if (board->players[player_number]->money >= board->cases[case_number].price
            && board->cases[case_number].owner != player_number
            && ask((char *)"Racheter ?"))
    {
        board->players[player_number]->money -= board->cases[case_number].price;
        board->players[board->cases[case_number].owner]->money += board->cases[case_number].price;
        board->cases->owner = player_number;
    }
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
            card = &CARDS[SHUFFLED_CARDS[board->current_card++]];
            display_card(card);
            getchar();
            return (card->effect(board, player_number, card->value));
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

board_t *initialize_board(void)
{
    board_t  *board;
    char buffer[100];
    int i;
    // creating board
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
        if (!strcmp(buffer, "Thomas666"))
            p->money *= 100;
        if (!(p->name = (char *)malloc((strlen(buffer) + 1) * sizeof(char))))
            exit(-1);
        if (!(strcpy(p->name, buffer)))
            exit(-3);
        p->position = 0;
        p->out = 1;
        board->players[i] = p;
    }
    return (board);
}

int main(void)
{
    board_t  *board;
    int de1, de2, replay;

    // seeding random algorithm
    srand(time(NULL));
    // shuffling cards
    shuffle_cards();

    board = initialize_board();
    //debut de partie
    board->current_player = 0;
    board->game_running = 1;
    replay = 0;
    display_board(board);

    while (board->game_running)
    {
        if (board->players[board->current_player]->out != 0)
        {
            player_t *player = board->players[board->current_player];
            de1= dice();
            de2 = dice();
            printf("Au tour de %s !", player->name);
            getchar();
            printf("%s lance les des : %d et %d (%d).\n", player->name, de1, de2, de1 + de2);
            board->doubles_in_row  = 0;
            // player is not in prison
            if (player->prison_for == 0)
            {
                // if double -> replay
                if (de1 == de2)
                {
                    replay++;
                    board->doubles_in_row++;
                    if (board->doubles_in_row == DOUBLE_PRISON)
                    {
                        player->position = 8;
                        player->prison_for = TIME_PRISON;
                    }
                }
                // move player and reward for turn
                player->position += de1 + de2;
                if (player->position >= CASE_COUNT)
                {
                    player->position = player->position % CASE_COUNT;
                    player->money += MONEY_TURN_REWARD;
                }
                display_board(board);
                // apply case effect
                replay += apply_case(board);
                if (player->money <= 0)
                    board->players[board->current_player]->out = 0;

            }
        }
        else
        {
            board->players[board->current_player]->prison_for--;
            if (de1 == de2)
            {
                printf("%s sort de prison !\n", board->players[board->current_player]->name);
                board->players[board->current_player]->prison_for = 0;
            }
        }
        display_board(board);
        if (!replay)
        {
            // next player
            board->current_player++;
            // reset double count
            board->doubles_in_row = 0;
            // all player played -> new round
            if (board->current_player >= board->player_number)
            {
                board->current_player = 0;
            }
        }
        replay = 0;
        if (is_won(board))
            board->game_running = 0;
    }
    return 0;
}
