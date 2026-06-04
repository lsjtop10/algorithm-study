#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void shellSort(int A[]) {
    printf("before sort \n");

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // i번째 데이터를 적절한 위치에 삽입
    for (int i = 1; i < N; i++) {
        int key = A[i];

        int j = i - 1;
        // 범위, 조건 체크
        // 크면 자기 걸 뒤로 밂.
        // 현재가 키보다 크면 1칸 뒤로 밂
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        printf("PASS %d>>> ", i + 1);
        for (int i = 0; i < N; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");

        // 이게 왜 j+1이지?
        // A[j]가 key보다 클 동안 j번째 값을 j+1번째로 민다.
        // 따라서 A[j]가 key보다 작거나 같다는 소리는
        // key가 A[j]번째로는 절대 들어갈 수 없다는 소리이고
        // 이 말은 A[j + 1]이 key의 위치라는 소리임.
        A[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    int A[10];

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
    }

    shellSort(A);
}