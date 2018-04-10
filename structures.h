#ifndef _STRUCTURES_H_
# define _STRUCTURES_H_

typedef struct  player_s
{
    int         id;
    char        *name;
    int         position;
    int         money;
}               player_t;


typedef struct  house_s
{
    int         owner;
}               house_t;

typedef struct  case_s
{
    char        *name;
    int         house_count;
    house_t     *houses;
    int         color;
    int         type;
}               case_t;
#endif /* _STRUCTURES_H_ */
