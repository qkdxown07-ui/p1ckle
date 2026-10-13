#include <stdio.h>

int main()
{
    int B = 7;

    printf("(*p)++ : %d\n", (*&B)++);
    printf("(*p)+1 : %d\n", (*&B)+1);
    printf("*p+=1 : %d\n", (*&B)+=1);
    printf("(*p)+=1 : %d\n", (*&B)+=1);
    printf("*p=*p+1 : %d\n", (*&B)=(*&B)+1);
    printf("++*p : %d\n", ++(*&B));
    printf("++(*p) : %d\n", B);

    return 0;
}