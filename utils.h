#ifndef _UTILS_H_
# define _UTILS_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define MAX(a, b)  (a > b ? a : b)

char    *my_itoa(int i);
char    *join(char *s, char **a, int c);
int     dice(void);
int     frand_2(int a,int b);
int     ask(char *s);

#endif /* _UTILS_H_ */
