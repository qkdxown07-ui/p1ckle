#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    FILE* file;     // 파일 포인터 선언
    char str1[] = "C language, ";
    char str2[] = "Text File!!!";

    // twostring.txt 파일을 쓰기 모드로 열기
    file = fopen("twostring.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일에 2개의 문자열 쓰기
    fprintf(file, "%s", str1);
    fprintf(file, "%s", str2);

    // 파일 닫기
    fclose(file);

    printf("twostring.txt 파일에 문자열 '%s%s'를 성공적으로 썼습니다.\n", str1, str2);
    return 0;
}
