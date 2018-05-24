#include "gui.h"


void    center_pad_str(char *s, int size)
{
    int ssize = 0;
    int pad;
    int i;

    if (s)
        ssize = strlen(s);
    pad = (size - ssize) / 2;
    for (i = 0; i < pad; i++)
        putchar(N_CHAR);
    if (s)
        fputs(s, stdout);
    for (i = 0; i < size - ssize - pad; i++)
        putchar(N_CHAR);
}

void    case_full(int iterations, char **content)
{
    int i;

    for (i = 0; i < iterations; i++)
    {
        putchar(V_CHAR);
        center_pad_str(content[i], H_SIZE);
    }
    putchar(V_CHAR);
}

void    case_fill(int iterations)
{
    int i;

    for(i = 0; i < H_SIZE * iterations + (iterations - 1); i++)
        putchar(N_CHAR);
}

void    case_partial(int iterations, char **content)
{
    putchar(V_CHAR);
    center_pad_str(content[0], H_SIZE);
    putchar(V_CHAR);
    case_fill(iterations - 2);
    putchar(V_CHAR);
    center_pad_str(content[1], H_SIZE);
    putchar(V_CHAR);
}

void    border_full(int iterations)
{
    int i, k;

    for (i = 0; i < iterations; i++)
    {
        putchar(X_CHAR);
        for (k = 0; k < H_SIZE; k++)
            putchar(H_CHAR);
    }
    putchar(X_CHAR);
}


void    border_partial(int iterations)
{
    border_full(1);
    case_fill(iterations - 2);
    border_full(1);
}

void    print_board(char ****info)
{
    int i, j;

    for (i = 0; i < GRID_SIZE; i++)
    {
        if (i == 0 || i == 1 || i == GRID_SIZE - 1)
            border_full(GRID_SIZE);
        else
            border_partial(GRID_SIZE);
        putchar('\n');
        for (j = 0; j < V_SIZE; j++)
        {
            if (i == 0 || i == GRID_SIZE - 1)
                case_full(GRID_SIZE, info[i][j]);
            else
                case_partial(GRID_SIZE, info[i][j]);
            putchar('\n');
        }
    }
    border_full(GRID_SIZE);
    putchar('\n');
}

char **formatted_case(board_t *board, int case_num, int *players, int players_count)
{
    char **r;
    char *t;
    char **p;
    case_t c = board->cases[case_num];
    int i;

    if (!(r = (char **)malloc(V_SIZE * sizeof(char *))))
        exit(-1);
    for (i = 0; i < V_SIZE; i++)
    {
        if (!(r[i] = (char *)malloc(H_SIZE * sizeof(char))))
            exit(-1);
        *(r[i]) = '\0';
    }
    switch (c.type)
    {
        case TYPE_STREET:
            r[0][0] = 'A' + c.category;
            strcpy(r[0] + 1, " - ");
            strcpy(r[0] + 4, c.name);
            r[0][4 + strlen(c.name)] = '\0';
            i = 0;
            if (c.owner >= 0)
            {
                t = my_itoa(c.owner);
                i = strlen(t);
                strcpy(r[1], t);
                strcpy(r[1] + i, " - ");
                i += 3;
            }
            r[1][i++] = '$';
            strcpy(r[1] + i, my_itoa(c.price));
            r[1][i + strlen(my_itoa(c.price))] = '\0';
            break;
        case TYPE_START:
            strcpy(r[0], "DEBUT");
            break;
        case TYPE_PRISON:
            strcpy(r[0], "PRISON");
            break;
        case TYPE_STATION:
            strcpy(r[0], "GARE ");
            strcpy(r[0] + 5, c.name);
            i = 0;
            if (c.owner >= 0)
            {
                t = my_itoa(c.owner);
                i = strlen(t);
                strcpy(r[1], t);
                strcpy(r[1] + i, " - ");
                i += 3;
            }
            r[1][i++] = '$';
            strcpy(r[1] + i, my_itoa(c.price));
            r[1][i + strlen(my_itoa(c.price))] = '\0';
            break;
        case TYPE_LUCKY:
            strcpy(r[1], "CHANCE");
            break;
        case TYPE_GOPRISON:
            strcpy(r[1], "ALLEZ EN PRISON");
            break;
        case TYPE_PARK:
            strcpy(r[1], "PARC");
            break;
        case TYPE_TAX:
            strcpy(r[1], "TAXE");
            break;
        default:
            break;
    }
    if (!(p = (char **)malloc(players_count * sizeof(char *))))
        exit(-1);
    for (i = 0; i < players_count; i++)
        p[i] = my_itoa(players[i]);
    r[3] = join((char *)", ", p, players_count);
    return (r);
}

char    ****board_info_convert(board_t *board)
{
    char ****info;
    char **formatted;
    int swap_box[2][CASE_COUNT];
    int *players_in_case;
    int i, j, players_in_case_c;

    if (!(info = (char ****)malloc(sizeof(char ***) * GRID_SIZE)))
        exit(-1);
    for (i = 0; i < GRID_SIZE; i++)
    {
        if (!(info[i] = (char ***)malloc(sizeof(char **) * V_SIZE)))
            exit(-1);
        for (j = 0; j < V_SIZE; j++)
            if (!(info[i][j] = (char **)malloc(sizeof(char *) * ((i == 0 || i == GRID_SIZE - 1) ? GRID_SIZE : 2))))
                exit(-1);
    }
    for (i = 0; i < GRID_SIZE; i++)
    {
        swap_box[0][i] = 0;
        swap_box[1][i] = i;
        swap_box[0][2 * GRID_SIZE - 2 + i] = GRID_SIZE - 1;
        swap_box[1][2 * GRID_SIZE - 2 + i] = GRID_SIZE - 1 - i;
    }
    for (i = 0; i < GRID_SIZE - 2; i++)
    {
        swap_box[0][GRID_SIZE + i] = i + 1;
        swap_box[1][GRID_SIZE + i] = 1;
        swap_box[0][3 * GRID_SIZE - 2 + i] = GRID_SIZE - 2 - i;
        swap_box[1][3 * GRID_SIZE - 2 + i] = 0;
    }
    if (!(players_in_case = (int *)malloc(sizeof(int) * board->player_number)))
        exit(-1);
    for (i = 0; i < CASE_COUNT; i++)
    {
        players_in_case_c = 0;
        for (j = 0; j < board->player_number; j++)
            if (board->players[j]->position == i)
                players_in_case[players_in_case_c++] = j;
        formatted = formatted_case(board, i, players_in_case, players_in_case_c);
        for (j = 0; j < V_SIZE; j++)
            info[swap_box[0][i]][j][swap_box[1][i]] = formatted[j];
    }
    return (info);
}

void    display_board(board_t *board)
{
    int i;

    print_board(board_info_convert(board));
    for (i = 0; i < board->player_number; i++)
    {
        if (board->players[i]->out)
            putchar('[');
        printf("%d=%s ($%d)", i, board->players[i]->name, board->players[i]->money);
        if (board->players[i]->out == 1)
            putchar(']');
        printf("    ");
    }
    printf("{JACKPOT: %d}\n", board->jackpot);
}

void display_card(card_t *card)
{
    int i;
    char *t, *t1;

    printf("%c", X_CHAR);
    for (i = 0; i < CARD_W - 2; i++)
        printf("%c", H_CHAR);
    printf("%c\n", X_CHAR);
    printf("%c", V_CHAR);
    center_pad_str((char *)"CARTE CHANCE", CARD_W - 2);
    printf("%c\n", V_CHAR);
    printf("%c", V_CHAR);
    center_pad_str(card->title, CARD_W - 2);
    printf("%c\n", V_CHAR);
    printf("%c", X_CHAR);
    for (i = 0; i < CARD_W - 2; i++)
        printf("%c", H_CHAR);
    printf("%c\n", X_CHAR);
    printf("%c", V_CHAR);
    center_pad_str((char *)"", CARD_W - 2);
    printf("%c\n", V_CHAR);
    printf("%c", V_CHAR);
    center_pad_str(card->desc, CARD_W - 2);
    printf("%c\n", V_CHAR);
    t = my_itoa(card->value);
    t1 = (char *)malloc((strlen(t) + 2) * sizeof(char));
    if (card->value)
    {
        t1[0] = '$';
        strcpy(t1 + 1, t);
    }
    else
    {
        t1[0] = '\0';
    }
    printf("%c", V_CHAR);
    center_pad_str(t1, CARD_W - 2);
    printf("%c\n", V_CHAR);
    printf("%c", V_CHAR);
    center_pad_str((char *)"", CARD_W - 2);
    printf("%c\n", V_CHAR);
    printf("%c", X_CHAR);
    for (i = 0; i < CARD_W - 2; i++)
        printf("%c", H_CHAR);
    printf("%c\n", X_CHAR);
}
