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
// je l'utilise pour les cartes chances

int randint(int a,int b)
{
    return ((rand() % (b-a)) + 1);
}

int     ask(char *s)
{
    char buffer[10];
    int ch;
    
    printf("%s (O/n) :", s);
    fgets(buffer, sizeof(buffer), stdin);
    // clear stdin buffer
    if (!strchr(buffer, '\n'))
        while (((ch = getchar()) != EOF) && (ch != '\n'));
    // parse buffer
    for (ch = 0; ch < (int)strlen(buffer); ch++)
    {
        if (buffer[ch] == 'O' || buffer[ch] == 'o')
            return (1);
        else if (buffer[ch] == 'N' || buffer[ch] == 'n')
            return (0);
        // not a valid answer
        else if ((buffer[ch] >= 'a' && buffer[ch] <= 'z')
                || (buffer[ch] >= 'A' && buffer[ch] <= 'Z'))
            return (ask(s));
    }
    return (1);
}
