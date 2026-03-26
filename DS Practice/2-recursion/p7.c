#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char InputString[101];

//이진 트리의 노드의 개수를 count하거나 높이를 잴 때와 상당히 유사한 연산임.
int countChars(char* string, int start, int end, char input){

    int cnt = (string[start] == input) ? 1: 0;

    //잘못된 조건절 수정
    if(start >= end){
        return cnt;
    }

    return cnt + countChars(string, start + 1, end, input);
}

int main(){
    char key; 

    scanf("%s", InputString);
    scanf(" %c", &key); //C언어에서 문자 입력받을 때는 buffer에 남아있는 개행이나 공백 문자가 넘어오므로 형식 문자열 %c 앞에 공백 하나 추가해주기

    printf("%d", countChars(InputString, 0, 101, key));


}