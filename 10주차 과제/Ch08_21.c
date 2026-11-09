#include <stdio.h>

int main()
{
    int arr[100];
    int x, i, cnt = 0;

    while (cnt < 100)
    {
        scanf("%d", &x);
        if (x == 0)
            break;
        arr[cnt++] = x;
    }

    printf("%d\n", cnt);

    for (i = 0; i < cnt; i++)
    {
        if (arr[i] % 2 != 0)
            printf("%d", arr[i] * 2);
        else
            printf("%d", arr[i] / 2);

        if (i < cnt - 1)
            printf(" ");
    }
    printf("\n");

    return 0;
}