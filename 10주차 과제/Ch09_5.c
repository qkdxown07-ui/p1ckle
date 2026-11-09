#include <stdio.h>

int main()
{
    int f[20];
    int i;

    f[0] = 1;
    f[1] = 1;

    for (i = 2; i < 20; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (i = 0; i < 20; i++)
    {
        printf("%d", f[i]);
        if (i < 19)
            printf(" ");
    }
    printf("\n");

    return 0;
}