#include <stdio.h>

int main()
{
    int arr[10];
    int i, sum = 0, odd_sum = 0;
    double avg;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 1)        // 짝수 번째 (2, 4, 6, 8, 10번째)
            sum += arr[i];
        else                   // 홀수 번째 (1, 3, 5, 7, 9번째)
            odd_sum += arr[i];
    }

    avg = odd_sum / 5.0;

    printf("sum : %d\n", sum);
    printf("avg : %.1f\n", avg);

    return 0;
}