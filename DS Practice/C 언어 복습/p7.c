#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    scanf("%d" , &num);

    int* arr1 = malloc( sizeof(int) * num);
    if(arr1 == NULL){
        return 1;
    }
    
    int* arr2 = malloc( sizeof(int) * num);
    if(arr1 == NULL){
        return 1;
    }

    for(int i = 0; i < num; i++){
        scanf("%d", &arr1[i]);
    }

    for(int i = 0; i < num; i++){
        scanf("%d", &arr2[i]);
    }

    for(int i = 0; i < num; i++){
        printf("%d ", arr1[i] + arr2[num - i - 1]);
    }



    free(arr1);
    free(arr2);

}