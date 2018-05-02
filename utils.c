#include "utils.h"

char    *my_itoa(int i)
{
    char digit[] = "0123456789";
    int n = i, l = 0;
    char *r, *p;

    while (n > 0)
    {
        l++;
        n = n / 10;
    }
    if (l == 0)
        return (char *)"0";
    if (!(r = (char *)malloc((l + 1) * sizeof(char))))
        exit(-1);
    p = r;
    r += l - 1;
    while (i > 0)
    {
        *(r--) = digit[i % 10];
        i = i / 10;
    }
    p[l] = '\0';
    return (p);
}

char    *join(char *s, char **a, int c)
{
    int l = 0, i, slen, n = 0;
    char *r;

    if (c == 0)
        return (char *)"\0";
    slen = strlen(s);
    for (i = 0; i < c; i++)
        l += strlen(a[i]);
    l += (c - 1) * slen;
    if (!(r = (char *)malloc(sizeof(char) * (l + 1))))
        exit(-1);
    for (i = 0; i < c ; i++)
    {
        strcpy(r + n, a[i]);
        n += strlen(a[i]);
        if (i != c - 1)
        {
            strcpy(r + n, s);
            n += slen;
        }
    }
    r[n] = '\0';
    return r;
}

int dice(void)
{
    return ((rand() % 6) + 1);
}
