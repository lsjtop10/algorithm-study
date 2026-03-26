#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
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

    int prev;
    scanf("%d", &prev);
    for(int i = 1; i < numSwap; i++){
        int next;
        scanf("%d", &next);

        swap(&data[prev], &data[next]);
    }


    for(int i = 0; i < size; i++){
        printf(" %d", data[i]);
    }
    
}