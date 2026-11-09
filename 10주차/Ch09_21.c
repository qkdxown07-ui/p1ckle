#include <stdio.h>

int main()
{
    int a[4][2];
    int rowSum[4] = {0};
    int colSum[2] = {0};
    int total = 0;
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
            total += a[i][j];
        }
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d", rowSum[i] / 2);
        if (i < 3)
            printf(" ");
    }
    printf("\n");

    for (j = 0; j < 2; j++)
    {
        printf("%d", colSum[j] / 4);
        if (j < 1)
            printf(" ");
    }
    printf("\n");

    printf("%d\n", total / 8);

    return 0;
}