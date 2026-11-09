#include <stdio.h>

int main()
{
    char arr[10];

    for(char i = 0; i < 10; i++){
        scanf("%c", &arr[i]);
    }
    for(char i = 0; i < 10; i++){
        printf("%c", arr[i]);
    }

    printf("\n");

    return 0;
}