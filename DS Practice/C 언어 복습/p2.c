#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열은 포인터로 받을 수 있음
void printArr(int* A){
    for(int i = 0; i < 10; i++){
        printf("%d ", *(A + i));
    }
}


void ABC(int *arr, int k){
    int maxIdx = k;

    for(int i = k + 1; i < 10; i++){
        if(arr[i] > arr[maxIdx]){
            maxIdx = i;
        }
    }

    int tmp = arr[maxIdx];
    arr[maxIdx] = arr[k];
    arr[k] = tmp;
}

int main(){
    int arr[10];
    printf("size: %d \n", (int)sizeof(arr));

    //난수발생
    //1 time.h 헤더

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        //why mod?
        arr[i] = rand() % 100;
    }

    for(int i = 0; i < 9; i++){
        ABC(arr, i);
    }

    printArr(arr);
}