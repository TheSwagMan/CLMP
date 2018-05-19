void apply_card_lucky(board_t *board, int player_id, chance_t *chance){

    if (chance->numero_de_la_carte == 0){
        printf("allez en prison");
        board->players[player_id]->position = 8;
        board->players[player_id]->prison_for = 2;
    }

    if (chance->numero_de_la_carte == 1){
        printf("Recevez 250$ de chaque joueur");
        board->players[player_id]->money += (250  * (board->player_number));
        int i;
        for (i = 0, i < board->player_number, i++)
        {
            if (i != player_id)
                board->players[player_id]->money -= 250;
        }
    }

    if (chance->numero_de_la_carte == 2){
        printf("Payer 200$ d'amende");
        board->players[player_id]->money -= 200;
        board->jackpot += 200;
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
        int c;
        printf("une rue ou une gare va etre réinitialiser");
        do {
            c = frand_2(0, CASE_NUMBER);
        } while (board->cases[c].type != TYPE_STREET || board->cases[c].type != TYPE_STATION);
        board->cases[c].owner = -1;
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
        board->players[player_id] -> objets = chance->numero_de_la_carte;

    }
    if(chance->numero_de_la_carte == 10){
        board->players[player_id] -> objets = chance->numero_de_la_carte;
    }
    if(chance->numero_de_la_carte == 11){
        board->players[player_id]-> objets = chance->numero_de_la_carte;
    }

}
