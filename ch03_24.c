#include <stdio.h>

int main()
{
    int a;
    
    scanf("%d", &a);

    printf("%s", a % 2 == 0 ? "Even" : "Odd");
    
    return 0;
}