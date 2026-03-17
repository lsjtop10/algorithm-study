#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//교수님은 size를 받음.
int max(int arr[], int to){
    
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


//꼬리재귀 최적화 버전
int maxOP(int arr[], int to, int max){
    
    if(to == 0){
        if (arr[to] > max){
            return arr[to];
        }

        return max;
    }

    int maxVal = maxOP(arr, to - 1, max);
}

int main(){
    int input[20];
    int size;

    srand(time(NULL));

    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        // scanf("%d", &input[i]);
        input[i] = rand() % 100;
        printf("%d ", input[i]);
    }
        printf("\n");

    int res = max(input, size - 1);

    printf("%d", res);
}