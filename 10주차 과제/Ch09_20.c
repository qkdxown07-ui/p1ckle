#include <stdio.h>

int main()
{
    int a[5][5] = {0};
    int i, j;

    a[0][0] = 1;
    a[0][2] = 1;
    a[0][4] = 1;

    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j > 0)
                a[i][j] += a[i - 1][j - 1];
            if (j < 4)
                a[i][j] += a[i - 1][j + 1];
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d", a[i][j]);
            if (j < 4)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}