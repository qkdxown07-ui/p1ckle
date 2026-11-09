#include <stdio.h>

int main()
{
    int p[5][5] = {0};
    int i, j;

    for (i = 0; i < 5; i++)
    {
        p[i][0] = 1;
        for (j = 1; j <= i; j++)
        {
            p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d", p[i][j]);
            if (j < i)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}