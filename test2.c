#include <stdio.h>

int main() 
{
    int try_dice[7] = {0};
    int n;

    for(int i= 0; i < 10; i++)
    {
        scanf("%d", &n);
        try_dice[n]++;
    }

    for (int i = 1; i <= 6; i++)
    {
        printf("%d : %d\n", i, try_dice[i]);
    }
}