#include <stdlib.h>
#include <stdio.h>

#define N 100

int arr[100][100];

int main(){
    int size;
    scanf("%d", &size);
   
    int cnt = 1;
    for(int i = 0; i <size; i++){
        if(i % 2 == 0){
            for(int j = 0; j < size; j++){

                arr[i][j] = cnt;
                cnt++;
            }
        }else{
            for(int j = size - 1; j >= 0; j--){
               
                arr[i][j] = cnt;
                cnt++;
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
}