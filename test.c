#include <stdio.h>
#include "utils.h"

int main(void)
{
    unsigned int n[6] = {0};
    for (int i = 0; i < 10000000; i++)
    {
        n[dice() - 1]++;
    }
    for (int i = 0; i < (int)(sizeof(n)/sizeof(unsigned int)); i++)
    {
        printf("%ud, ", (unsigned int)n[i]);
    }
    return 0;
}
