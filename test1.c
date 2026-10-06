#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i]; // 삽입할 대상 요소 선정
        j = i - 1;

        // key보다 큰 요소들을 오른쪽으로 한 칸씩 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // key 삽입
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

    insertionSort(arr, n);

    printf("삽입 정렬 결과: ");
    printArray(arr, n);

    return 0;
}

/* 동작과정
[8] 5 2 6 4 -> 5를 8 앞에 삽입 -> [5, 8] 2 6 4
[5, 8] 2 6 4 -> 2를 맨 앞에 삽입 -> [2, 5, 8] 6 4
[2, 5, 8] 6 4 -> 6을 5와 8 사이에 삽입 -> [2, 5, 6, 8] 4
[2, 5, 6, 8] 4 -> 4를 2와 5 사이에 삽입 -> [2, 4, 5, 6, 8]*/