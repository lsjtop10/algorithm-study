#include <stdio.h>
#include <stdlib.h>

char InputString[101];

int countChars(char* string, int start, int end, char input){

    int cnt = string[start] == input ? 1: 0;

    if(start > end && string[start] == input){
        return cnt;
    }

    return cnt + countChars(string, start + 1, end, input);
}

int main(){
    char key; 

    scanf("%s", InputString);
    scanf("%c", &key);

    printf("%d", countChars(InputString, 0, 101, key));


}