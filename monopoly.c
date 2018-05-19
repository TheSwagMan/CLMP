#include "monopoly.h"


void apply_case(board_t *board)
{
    char buff[10];
    int player_number = board->current_player;
    int case_number = board->players[player_number]->position;

    //Actions lorsqu'on arrive sur une case, effets produits
    if (board->cases[case_number].type==TYPE_STREET)  //arrive sur une case rue
    {
        if (board->cases[case_number].owner == -1)             //personne n'a la case
        {
            if (board->players[player_number]->money >= board->cases[case_number].initial_price)        //assez d'argent pour acheter?
            {
                printf("Acheter ? (0/1)");                  //à mieux rédiger
                fgets(buff, 10, stdin);
                if (atoi(buff))
                {
                    board->players[player_number]->money = board->players[player_number]->money - board->cases[case_number].initial_price;
                    board->cases[case_number].owner = player_number;                    //achat de la case
                }
            }
        }
        else //qqn a la case
        {
        if (board->players[player_number]->money < board->cases[case_number].price) // si pas assez d'argent pour payer (price à voir)
        {
            // NO
            board->players[player_number]->money += board->cases[case_number].price;
            printf("Revendez"); //obligation de revendre un bien immobilier
            // à compléter
        }
        else
        {
            board->players[player_number]->money -= board->cases[case_number].price;
        }

            board->players[player_number]->money -= board->cases[case_number].price; // paye le loyer (price à revoir)
        }
        /*
        if(Racheter)          //Rachat de la rue
        {
            board->player[i]->money = board->player[i]->money + price;
            board->cases->owner = i;
        }*/
    }

    if(board->cases->type==TYPE_GOPRISON) //arrive sur une case lui disant d'aller direct en prison
    {
        board->players[player_number]->position = 8;
        //à compléter
    }

    if(board->cases->type==TYPE_STATION)   //arrive sur une case type gare
    {
        if(board->cases->owner==-1)           //personne n'a la case
        {
            if(board->players[player_number]->money > board->cases[case_number].initial_price)    //assez d'argent pour acheter
            {
                printf("Acheter?");
            }
            /*
            if(acheter)
            {
                board->player[i]->money = board->player[i]->money - initial_price;
                board->cases->owner = i;                //achète et possède la case
            }
            else
            {
                board->player[i]->money = board->player[i] - price;    //price à voir
                }
                */
        }
    }

    if(board->cases->type == TYPE_TAX)  //arrive sur une case taxe
    {
        board->players[player_number]->money -= 200;
        board->jackpot += 200; //CAGNOTTE est une variable stockant l'argent perdu lors des actions sur le board( ex: prison, taxes, etc...)
    }

    if(board->cases->type == TYPE_PARK) //arrive sur la case CAGNOTTE
    {
        board->players[player_number]->money += board->jackpot; //gagne l'argent stocké dans la CAGNOTTE
        board->jackpot = 0;
    }

}


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


//Je sais pas trop où le mettre donc je place ici mon programme à compléter (#JR)
