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
    int         color;
    int         type;
    int         owner;
}               case_t;
#endif /* _STRUCTURES_H_ */
