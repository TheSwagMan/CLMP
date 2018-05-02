#include "monopoly.h"
srand(time(NULL));
int frand_2(int a,int b)
{
    return ((rand() % (b-a)) + 1);
}
void apply_card_prison(board_t board,int player_id,chance_t chance){
     if(chance->numero_de_la_carte==0){
        printf("allez en prison")
        board->players[player_id]->position = 8;
     }
     if(chance->numero_de_la_carte==1){
        printf("Recevez 250$ de chaque joueur");
        board->players[player_id]->money += (250  * (board->player_number));
     }
     if(chance->numero_de_la_carte==2){
        printf("Payer 200$ d'amende")
        board->players[player_id]-> money -= 200;
     }
     if(chance->numero_de_la_carte==3){
        printf("vous pouvez rejouer");

     }
     if(chance->numero_de_la_carte==4){
        t[4]={4,11,21,27};
        int c=frand_2(0,4);
        printf("allez à la gare: &s",board->cases[nombre].name);
        board->players[player_id]->position= t[C];
     }
     if(chance->numero_de_la_carte==5){
        int nombre= frand_2(1,33);
        if( nombre != 3 || nombre != 4 || nombre  !=  6 || nombre !=  8 || nombre !=  11 ||nombre !=  13 || nombre  !=  16 || nombre  !=  18 ||nombre !=  21 || nombre != 24 || nombre != 27 || nombre != 28 || nombre != 30 ){
            printf("allez à :&s",board->cases[nombre].name);
            board->players[player_id]->position = nombre;
        }
     }
     if( chance->numero_de_la_carte==6){
        int nombre=frand_2(1,33)
        printf("une rue ou une gare va etre réinitialiser");
        if(nombre != 3 || nombre  !=  6 || nombre !=  8 ||nombre !=  13 || nombre  !=  16 || nombre  !=  18 || nombre != 24 || nombre != 28 || nombre != 30 ){
          board->cases[nombre].owner = -1;
          }
    }

    if (chance->numero_de_la_carte == 7){
        printf("allez au centre des impôts");
        board->players[player_id]->position = 3;
     }
     if (chance->numero_de_la_carte == 8){
        printf("allez au parc gratuit");
        board->players[player_id]->position = 16;
      }
      if(chance->numero_de_la_carte == 9){
         board-> players[player_id] -> objets = chance->numero_de_la_carte;

    }
    if(chance-> numero_de_la_carte == 10){
       board->  players[player_id] -> objets = chance->numero_de_la_carte;
    }
    if(chance -> numero_de_la_carte == 11){
      board->  players[player_id]-> objets = chance->numero_de_la_carte;
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
//debut de partie
int player_now = 0;
while (!victoire)
{
    int lancer1 = dice();
    int lancer2 = dice();

    printf("&s lance 2 des : &d et &d \n",board->players[player_now],lancer1,lancer2);
    board->players[player_now]->position += lancer1 + lancer2;
    if (lancer1 == lancer2)
    {
        lancer1 = dice();
        lancer2 = dice();
        printf("Double !! les des sont relances : &d et &d", lancer1, lancer2);
    }
    if (player_now<board->player_number)
      player_now += 1;
    else
      player_now = 0;
}
return 0;
}
