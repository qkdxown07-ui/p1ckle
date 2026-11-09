#include <stdio.h>

int main()
{
    int x, cnt = 0, sum = 0;
    int total = 0;
    double avg = 0.0;

    while (total < 100)
    {
        scanf("%d", &x);
        if (x == 0)
            break;
        total++;
        if (x % 5 == 0)
        {
            cnt++;
            sum += x;
        }
    }

    if (cnt > 0)
        avg = (double)sum / cnt;

    printf("Multiples of 5 : %d\n", cnt);
    printf("sum : %d\n", sum);
    printf("avg : %.1f\n", avg);

    return 0;
}