#include <stdio.h>

int main()
{
    int a[1000];
    int n, i;

    scanf("%d", &n);

    a[0] = 100;
    a[1] = n;
    i = 1;

    while (a[i] >= 0)
    {
        i++;
        a[i] = a[i - 2] - a[i - 1];
    }

    for (int j = 0; j <= i; j++)
    {
        printf("%d", a[j]);
        if (j < i)
            printf(" ");
    }
    printf("\n");

    return 0;
}