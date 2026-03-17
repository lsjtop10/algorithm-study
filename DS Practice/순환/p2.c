#include <stdio.h>
#include <stdlib.h>

void printNum(int num){
    
    if(num < 10){
        printf("%d  \n", num);
        return;
    }

    // 10으로 나눈 몫 중 큰 자리부터 출력 
    printNum(num / 10);
    // 1의 자리 출력
    printf( "%d \n",num % 10);
}

int main(){
    int input;
    scanf("%d", &input);

    printNum(input);
}