#include <stdio.h>

#define MAX_STUDENTS 50

int main()
{
    int Student;
    int Score[MAX_STUDENTS];
    int *jumsoo; // 포인터 선언이긴 하지만 잘 모르겠음.
    

    printf("학생 수를 입력해주세요 : ");
    scanf("%d", &Student);

    if (Student > MAX_STUDENTS)
    {
        printf(" 학생 수용 최대 인원보다 기입한 학생의 수가 많습니다.\n");
        return 0;
    }
    else if (Student <= 0)
    {
        printf("학생 수는 1명 이상이어야 합니다.\n");
        return 0;
    }

    while (1)
    {
        int jumsoo;
        
        printf("점수를 입력하시오.(0~100) : ");
        scanf("%d", &jumsoo);



    }
}