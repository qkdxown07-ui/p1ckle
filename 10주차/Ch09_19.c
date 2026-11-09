#include <stdio.h>

int main()
{
    int a[3];
    int i, j, sum, total = 0;

    for (i = 0; i < 4; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[j]);
            sum += a[j];
        }
        printf("%d\n", sum);
        total += sum;
    }

    printf("%d\n", total);

    return 0;
}