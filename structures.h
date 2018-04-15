#ifndef _STRUCTURES_H_
# define _STRUCTURES_H_

typedef struct  player_s
{
    int         id;
    char        *name;
    int         position;
    int         money;
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
    case_t      **cases;
    int         player_number;
    player_t    **players;

}               board_t;

enum            CASE_TYPES
{
    TYPE_STREET = 0,
    TYPE_PRISON,
    TYPE_LUCKY,
    TYPE_STATION,
    TYPE_PARC,
    TYPE_TAX
};

#endif /* _STRUCTURES_H_ */
