#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i; // 최솟값의 위치를 일단 현재 위치로 설정

        // 현재 위치 다음부터 끝까지 탐색하며 최솟값의 인덱스 찾기
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // 찾은 최솟값을 현재 위치(i)의 요소와 교환
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 5, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("원래 배열: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("선택 정렬 결과: ");
    printArray(arr, n);

    return 0;
}

/* 동작과정
전체에서 최솟값 2 선택 -> 맨 앞의 8과 교환 -> [2] 5 8 6 4
나머지에서 최솟값 4 선택 -> 두 번째 5와 교환 -> [2, 4] 8 6 5
나머지에서 최솟값 5 선택 -> 세 번째 8과 교환 -> [2, 4, 5] 6 8
나머지에서 최솟값 6 선택 -> 제자리 유지 -> [2, 4, 5, 6, 8]*/