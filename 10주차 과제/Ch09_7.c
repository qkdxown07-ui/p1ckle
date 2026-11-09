#include <stdio.h>

int main()
{
    int arr[5] = {95, 75, 85, 100, 50};
    int i, j, tmp;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
        if (i < 4)
            printf(" ");
    }
    printf("\n");

    return 0;
}