#include <stdio.h>

int main()
{
    int a,b=0;

    printf("세 자리 자연수를 입력하시오 > ");
    scanf("%d", &a);
    
    printf("세 자리 자연수를 입력하시오 > ");
    scanf("%d", &b);

    int temp =b;
    while (temp > 0)
    {
        printf("%d\n", a*(temp%10));
        temp /= 10;
    }
    printf("각 자릿수의 곱 : %d", a*b);

    return 0;
}