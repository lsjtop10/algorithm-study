#include <stdio.h>
#include <stdlib.h>

// printNum 함수의 정의: num으로 들어온 수를 가장 마지막 자리부터 출력
void printNum(int num){
    
    if(num < 10){
        printf("%d  \n", num);
        return;
    }

    // 먼저 1의 자리를 출력함
    printf( "%d \n",num % 10);
    // 10으로 나눈 값 중 마지막 자리부터 출력.
    printNum(num / 10);
}

int main(){
    int input;
    scanf("%d", &input);

    printNum(input);
}