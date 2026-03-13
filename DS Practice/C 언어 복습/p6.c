#include<stdio.h>
#include<stdlib.h>

#define NUM 5

typedef struct{
    int score;
    char student_name[10];
} Exem;

int main(){
    int sum = 0;
    Exem exems[NUM];
    
    for(int i = 0; i < NUM; i++){
        scanf("%s %d", exems[i].student_name, &exems[i].score);
        sum += exems[i].score;
    }

    int average = sum / NUM;

    for(int i = 0; i < NUM; i++){
        if(exems[i].score <= average){
            printf("%s \n", exems[i].student_name);
        }
    }
    
}
