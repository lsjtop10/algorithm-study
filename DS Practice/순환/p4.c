#include <stdio.h>

int max(int* arr, int to){
    if(to == 0){
        return arr[to];
    }

    int maxVal = max(arr, to - 1);

    if( maxVal < arr[to]){
        return arr[to];
    }else{
        return maxVal;
    }
}

int main(){
    int input[20];
    int size;

    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        scanf("%d", &input[i]);
    }

    int res = max(input, size - 1);

    printf("%d", res);
}