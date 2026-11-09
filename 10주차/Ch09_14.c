#include <stdio.h>

int main()
{
    int a[5][5];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 0 || j == 0)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j] + a[i][j - 1];
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