#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 1부터 100 사이에 숫자를 맞추는 프로그램 */
int main()
{
    int answer;
    int num;
    int count = 0;
    
    srand(time(NULL));

    answer = rand() % 100 +1;

    printf("1부터 100 사이의 숫자를 하나 맞춰보세요 ! ");

    while(1)
    {
        printf("숫자를 입력하시오 > ");
        if (scanf("%d", &num) != 1)
        {
            printf("숫자만 입력하세요.\n");
            return 1;
        }
        count++;

        if(num > answer)
        {
            printf("더 작은 수 입니다.\n");
        }
        else if(num < answer)
        {
            printf("더 큰 수 입니다.\n");
        }
        else
        {
            printf("정답입니다.\n");
            printf("%d번 반복하여 맞추셨습니다.\n", count);
            break;
        }

    }


}