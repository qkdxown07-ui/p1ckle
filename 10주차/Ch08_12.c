#include <stdio.h>

int main()
{
    int arr[100];
    int x, i, cnt = 0;
    int max, min;

    while (1)
    {
        scanf("%d", &x);
        if (x == 0)
            break;
        arr[cnt++] = x;
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < cnt; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("%d\n", max - min);

    return 0;
}