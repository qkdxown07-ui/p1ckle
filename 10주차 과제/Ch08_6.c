#include <stdio.h>

int main()
{
    int a[100];
    int n = 0;
    int x;

    while(n < 100){
        scanf("%d", &x);
        if(x == 0) break;
        a[n++] = x;
    }
    for(int i = n - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }

    return 0;
}