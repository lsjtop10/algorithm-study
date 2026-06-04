#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void mergeSort(int A[]) {
    printf("before sort \n");

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    for (int i = N - 1; i > 0; i--) {

        int isSwapOccered = 0;

        for(int j = 0; j < i; j++){
            if(A[j] > A[j+1]){
                int tmp = A[j+1];
                A[j+1] = A[j];
                A[j] = tmp;
                isSwapOccered = 1;
            }
        }

        // swap이 한 번도 일어나지 않으면 루프 종료?
        // 이게 최적화? -> 한번 다시 보기
        // -> 버블 sort는 순서가 맞지 않으면 sort가 발생함.
        if(isSwapOccered == 0){
            break;
        }

        printf("PASS %d>>> ", N - 1);
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

    mergeSort(A);
}