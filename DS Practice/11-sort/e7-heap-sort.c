#include <stdio.h>
#include <stdlib.h>

#define N 11 // 0번은 dummy
#define SIZE 10

void heapify(int arr[], int idx, int arrSize) {
    int largest = idx;

    // 2 * idx < size일 때 <=가 아니라 <임. 왜???
    // -> 배열의 크기 - 1이 유효한 마지막 인덱스잖아.
    // FIXME: heapfify 로직 한 번 보기
    // 배열의 크기와 heap의 크기는 다름 ㅇㅇ
    if (2 * idx < arrSize && arr[largest] < arr[2 * idx]) {
        largest = 2 * idx;
    } 
    //왼쪽 자식을 검사하는 로직과 오른쪽 자식을 검사하는 로직을 else-if로 이어붙이면 안 된다.
    if (2 * idx + 1 < arrSize && arr[largest] < arr[2 * idx + 1]) {
        largest = 2 * idx + 1;
    }

    if(largest != idx){
        
        int tmp = arr[idx];
        arr[idx] = arr[largest];
        arr[largest] = tmp;

        heapify(arr, largest, arrSize);
    }

}

void printHeap(int A[], int size){
    for(int i = 1; i < size; i++){
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

void buildHeap(int arr[], int size) {
    for (int i = size / 2; i > 0; i--) {
        heapify(arr, i, size);
    }
}

void heapSort(int arr[], int size){
    buildHeap(arr, N);
    printHeap(arr, N);
    printf("-------------------------------------------\n");

    for(int i = size - 1; i > 1; i--){
        int tmp = arr[i];
        arr[i] = arr[1];
        arr[1] = tmp;
        heapify(arr, 1, i);
        printHeap(arr, N);
    }


}

int main() {
    int A[N] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    
    heapSort(A, N);
    printHeap(A, N);
}
