#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    FILE* filePtr;
    char filename[] = "example.txt";     // 저장할 파일명을 담는 문자열

    // 파일을 쓰기 모드로 열기
    filePtr = fopen(filename, "w");

    // 파일 열기에 실패했는지 확인
    if (filePtr == NULL) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return 1;     // 오류 코드 반환 후 프로그램 종료
    }

    // 파일에 문자열 쓰기
    fprintf(filePtr, "Hello, world!\n");

    // 파일 닫기
    fclose(filePtr);

    printf("%s 파일에 데이터를 성공적으로 썼습니다.\n", filename);

    return 0;
}
