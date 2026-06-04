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

    // int gap = N / 2;

    // // 뭔가 교과서에서 봤던 로직이랑 다른데...
    // while (gap > 0) {

    //     for (int i = gap; i < N; i++) {
    //         int key = A[i];

    //         int j = i - gap;
    //         // 범위, 조건 체크
    //         // 크면 뒤로 밂.
    //         while (j >= 0 && A[j] > key) {
    //             A[j + gap] = A[j];
    //             j -= gap;
    //         }

    //         // 이게 왜 j+1이지?
    //         A[j + gap] = key;
    //     }

    //     gap /= 2;
    //     printf("%d PASS >>> ", gap);

    //     for (int i = 0; i < N; i++) {
    //         printf("%d ", A[i]);
    //     }
    //     printf("\n");
    // }

    for(int gap = N /2; gap > 0 ;gap /= 2){
        if( gap % 2 == 0 ){
            gap++;
        }


        for(int i = gap; i < N; i++){
            int j = i - gap;
            int key = A[i];

            // 현재가 크면 다음으로 미루는 것임.
            while (j >= 0 &&  A[j] > key){
                A[j + gap] = A[j];
                j -= gap;
            }
            
            A[j + gap] = key;

        }        

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