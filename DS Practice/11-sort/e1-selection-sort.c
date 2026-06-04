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

    for (int i = 0; i < N - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[minIdx]) {
                minIdx = j;
            }
        }

        // 최적화
        if (minIdx != i) {
            int tmp = A[minIdx];
            A[minIdx] = A[i];
            A[i] = A[minIdx];
        }

        printf("PASS %d>>>", i + 1);
        for (int i = 0; i < N; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
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