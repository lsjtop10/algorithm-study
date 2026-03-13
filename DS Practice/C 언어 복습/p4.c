#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    char buf[101];
    scanf("%s", buf);
    int len = strlen(buf);

    printf("%s\n", buf);
    for(int i = 0; i < len - 1; i++){
        char tmp = buf[0];
        for(int j = 0; j < len - 1; j++){
            swap(&buf[j], &buf[j+1]);
        }
        buf[len - 1] = tmp;
        printf("%s\n", buf);
    }
}