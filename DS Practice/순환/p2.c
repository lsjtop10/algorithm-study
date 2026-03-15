#include <stdio.h>
#include <stdlib.h>

void printNum(int num){
    
    if(num < 10){
        printf("%d  \n", num);
        return;
    }

    printNum(num / 10);
    printf( "%d \n",num % 10);
}

int main(){
    int input;
    scanf("%d", &input);

    printNum(input);
}