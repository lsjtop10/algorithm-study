#include<stdio.h>
#include<stdlib.h>

void swap(int* p1, int* p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(){
    int size;
    int arr[50];
    int a, b;

    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &a, &b);

    swap(&arr[a], &arr[b]);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}