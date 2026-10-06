#include <stdio.h>

int main()
{
    for (int i = 1; i <= 5; i++) {
        // 공백 출력 (5 - i개 만큼 공백)
        for (int j = 0; j < 5 - i; j++) {
            printf(" ");
        }
        // 별 출력
        for (int j = 0; j <= i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}