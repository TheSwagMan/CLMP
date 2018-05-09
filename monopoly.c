#include "monopoly.h"


void apply_card_prison(board_t *board, int player_id, chance_t *chance){
     if (chance->numero_de_la_carte == 0){
        printf("allez en prison");
        board->players[player_id]->position = 8;
     }
     if (chance->numero_de_la_carte == 1){
        printf("Recevez 250$ de chaque joueur");
        board->players[player_id]->money += (250  * (board->player_number));
     }
     if (chance->numero_de_la_carte == 2){
        printf("Payer 200$ d'amende");
        board->players[player_id]-> money -= 200;
     }
     if (chance->numero_de_la_carte == 3){
        printf("vous pouvez rejouer");
     }
     if (chance->numero_de_la_carte == 4){
        int t[] = {4, 11, 21, 27};
        int c = frand_2(0, sizeof(t));
        printf("allez à la gare: %s", board->cases[t[c]].name);
        board->players[player_id]->position= t[c];
     }
     if (chance->numero_de_la_carte==5){
        int t[] = {3, 4, 6, 8, 11, 13, 16, 18, 21, 24, 27, 28, 30};
        int c = frand_2(0, sizeof(t));
        printf("allez à : %s",board->cases[t[c]].name);
        board->players[player_id]->position = t[c];
     }
     if (chance->numero_de_la_carte == 6){
        int nombre=frand_2(1,33);
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

    //debut de partie
    int player_now = 0;
    while (1)
    {
        int lancer1 = dice();
        int lancer2 = dice();

        printf("%s lance 2 des : %d et %d \n", board->players[player_now]->name, lancer1, lancer2);
        if (board->players[player_now]->prison_for == 0)
            board->players[player_now]->position = (board->players[player_now]->position + (lancer1 + lancer2)) % CASE_COUNT;
        else
        {
            if (lancer1 == lancer2)
            {
                printf("%s sort de prison",board->players[player_now]->name);
                board->players[player_now]->prison_for = 0;
            }
            else
                board->players[player_now]->prison_for -=1;
        }

        if (player_now<board->player_number)
            player_now += 1;
        else
            player_now = 0;
    }
    return 0;
}


//Je sais pas trop où le mettre donc je place ici mon programme à compléter (#JR)
//Actions lorsqu'on arrive sur une case, effets produits
if (board->cases->type==TYPE_STREET)  //arrive sur une case rue
{
  if (board->cases->owner==-1)             //personne n'a la case
  {
    if (board->player[i]->money => initial_price)        //assez d'argent pour acheter?
    {
      printf "Acheter?";                  //à mieux rédiger
          if(Acheter)
          {
            board->player[i]->money = board->player[i]->money - initial_price;
            board->cases->owner = i;                    //achat de la case
          }
    }
  }
  else //qqn a la case
  {
    board->player[i]->money = board->player[i]->money - price; // paye le loyer (price à revoir)
  }
    if (board->player[i]->money - price =< 0) // si pas assez d'argent pour payer (price à voir)
    {
      board->player[i]->money = board->player[i]->money + price;
      board->cases->owner = i;
      printf("Revendez"); //obligation de revendre un bien immobilier
      // à compléter
    }
    else
    {
      board->player[i]->money = board->player[i]->money - price;
      printf ("Racheter?");         //à mieux rédiger, rachat de la rue?
    }
      if(Racheter)          //Rachat de la rue
      {
        board->player[i]->money = board->player[i]->money + price;
        board->cases->owner = i;
      }
}

if(board->cases->type==TYPE_GOPRISON) //arrive sur une case lui disant d'aller direct en prison
{
  board->player[i]->position = 8;
  //à compléter
}

if(board->cases->type==TYPE_STATION)   //arrive sur une case type gare
{
  if(board->cases->owner==-1)           //personne n'a la case
  {
    if(board->player[i]->money > initial_price)    //assez d'argent pour acheter
    {
      printf"Acheter?";
    }
      if(acheter)
      {
        board->player[i]->money = board->player[i]->money - initial_price;
        board->cases->owner = i;                //achète et possède la case
      }
      else
      {
        board->player[i]->money = board->player[i] - price;    //price à voir
      }
  }
}

if(board->cases->type==TYPE_TAX)  //arrive sur une case taxe
{
  board->player[i]->money = board->player[i]->money - TAX;
  CAGNOTTE = CAGNOTTE + TAX; //CAGNOTTE est une variable stockant l'argent perdu lors des actions sur le board( ex: prison, taxes, etc...)
}

if(board->cases->type==TAXE_PARK) //arrive sur la case CAGNOTTE
{
  board->player[i]->money = board->player[i]->money + CAGNOTTE; //gagne l'argent stocké dans la CAGNOTTE
}
//ok//ok//ok