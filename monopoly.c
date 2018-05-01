#include "monopoly.h"


#include "monopoly.h"
void apply_card_prison(board_t board,int player_id,chance_t chance){
     if(chance->numero_de_la_carte==0){
        pritnf("allez en prison")
        return board->player_id->position=board->case[8];
     }
     if(chance->numero_de_la_carte==1){
        printf("Recevez 250$ de chaque joueur");
        return board->players_t->money = money  + (250  * (board->player_number));
     }
     if(chance->numero_de_la_carte==2){
     printf("Payer 200$ d'amende")
       return board->players_t->money = money - 200;
     }
     if(chance->numero_de_la_carte==3){
      printf("vous pouvez rejouer");
      return 0;
     }
     if(chance->numero_de_la_carte==4){
        t[4]={{board->case[4]},{board->case[11]},{board->case[21]},{board->case[27]}};
        int c=frand_2(0,4);
        printf("allez à la gare: &s",t[c]->name)
        return board->player_id->position=t[C];
     }
     if(chance->numero_de_la_carte==5){
        int nombre= frand_2(1,33);
        if( nombre != 3 || nombre != 4 || nombre  !=  6 || nombre !=  8 || nombre !=  11 ||nombre !=  13 || nombre  !=  16 || nombre  !=  18 ||nombre !=  21 || nombre != 24 || nombre != 27 || nombre != 28 || nombre != 30 ){
        printf("allez à :&s",board->case[nombre]->name);
          return board->player_id->position =  board->case[nombre];
        }
     }
     if( chance->numero_de_la_carte==6){
        int nombre=frand_2(1,33)
        printf("entrer le nom une rue ou une gare va etre revendue");
        if(nombre != 3 || nombre  !=  6 || nombre !=  8 ||nombre !=  13 || nombre  !=  16 || nombre  !=  18 || nombre != 24 || nombre != 28 || nombre != 30 ){
           return board->cases[nombre].owner = -1;
          }
    }

    if (chance->numero_de_la_carte == 7){
        printf("allez au centre des impôts");
        return board->player_id->position=board->case[3];
     }
     if (chance->numero_de_la_carte == 8){
         printf("allez au parc gratuit");
         return board->player_id->position=board->case[16];
      }
      if(chance->numero_de_la_carte == 9){
        return board-> player_id -> objet = chance->numero_de_la_carte;

    }
    if(chance-> numero_de_la_carte == 10){
      return  board-> player_id -> objet = chance->numero_de_la_carte;
    }
    if(chance -> numero_de_la_carte == 11){
      return  board-> player_id -> objet = chance->numero_de_la_carte;
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
        p->money = 100;
        if (!(p->name = (char *)malloc((strlen(buffer) + 1) * sizeof(char))))
            exit(-1);
        if (!(strcpy(p->name, buffer)))
            exit(-3);
        p->position = 0;
        board->players[i] = p;
    }
    printf("-\n");
    // displaying board for debug
    display_board(board);
    return 0;
}
