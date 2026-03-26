#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void swapArr(int arr[], int from, int to){
    while(true){

        if(from >= to){
            return;
        }
        
        swap(&arr[from], &arr[to]);
        from++;
        to--;
    }
}

int main(){
    int size;
    int data[101] = {0,};

    int numSwap;

    scanf("%d", &size);
    
    for(int i = 0; i < size; i++){
        scanf("%d", &data[i]);
    }

    scanf("%d", &numSwap);

    for(int i = 0; i < numSwap; i++){
        int start;
        int end;

        scanf("%d %d", &start, &end);
        swapArr(data, start, end);
    }


    for(int i = 0; i < size; i++){
        printf(" %d", data[i]);
    }
    
}