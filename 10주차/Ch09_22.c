#include <stdio.h>

int main()
{
    int p[10][10] = {0};
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i][0] = 1;
        for (j = 1; j <= i; j++)
        {
            p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
        }
    }

    for (i = n - 1; i >= 0; i--)
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