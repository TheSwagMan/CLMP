#ifndef _STRUCTURES_H_
# define _STRUCTURES_H_

typedef struct  player_s
{
    char        *name;
    int         position;
    int         money;
    int         objets;
    int         prison_for;
}               player_t;


typedef struct  case_s
{
    char        *name;
    int         category;
    int         type;
    int         owner;
    int         initial_price;
    int         price;
}               case_t;

typedef struct  board_s
{
    case_t      *cases;
    int         player_number;
    player_t    **players;
    int         jackpot;
    int         current_player;
    int         game_running;
}               board_t;

typedef struct carte_chance
{
    char        *title;
    char        *desc;
    int         value;
    void        (*effect)(int);
    int         keep;
}                     chance_t;

enum            CASE_TYPES
{
    TYPE_STREET = 0,
    TYPE_PRISON,
    TYPE_LUCKY,
    TYPE_STATION,
    TYPE_PARK,
    TYPE_TAX,
    TYPE_START,
    TYPE_GOPRISON
};

#endif /* _STRUCTURES_H_ */
