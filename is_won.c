
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
    int playing = 1;
    board->current_player = 0;
    board->game_running = 1;
    replay = 0;
    display_board(board);

    while (board->game_running && playing == 1)
    {

        if (board->players[board->current_player]->out != 0)
        {
            player_t *player = board->players[board->current_player];
            de1= dice();
            de2 = dice();
            printf("Au tour de %s !", player->name);
            getchar();
            printf("%s lance les des : %d et %d (%d).\n", player->name, de1, de2, de1 + de2);
            getchar();
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
                getchar();
                // apply case effect
                replay += apply_case(board);
                if (player->money <= 0)
                    board->players[board->current_player]->out = 0;

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
        is_won(board_t *board);
    }
    return 0;
}
