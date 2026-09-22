#include <stdio.h>

int main()
{
    int number;
    
    printf("정수 하나를 입력하시오 > ");
    scanf("%d", &number);
    
    printf("%s", (number % 2==0)?"Even":"Odd");

    return 0;

}