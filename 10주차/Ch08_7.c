#include <stdio.h>

int main()
{
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m;

    while(1){
        scanf("%d", &m);
        if(m < 1 || m > 12) break;
        printf("%d\n", a[m - 1]);
    }

    return 0;
}