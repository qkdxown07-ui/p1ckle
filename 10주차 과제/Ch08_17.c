#include <stdio.h>

int main()
{
    int arr[10];
    int i, odd = 0, even = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            odd += arr[i];
        else
            even += arr[i];
    }

    printf("odd : %d\n", odd);
    printf("even : %d\n", even);

    return 0;
}