#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int h;
    int m;
    int s;
}Time;


int main(){
    Time t1;
    Time t2;

    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    int secs1 = t1.h * 3600 + t1.m * 60 + t1.s;
    int secs2 = t2.h * 3600 + t2.m * 60 + t2.s;

    int diffSecs = secs2 - secs1; 

    Time diff = {0,0,0};

    diff.h = diffSecs / 3600;
    diffSecs = diffSecs % 3600;

    diff.m = diffSecs / 60;
    diff.s = diffSecs % 60;

    printf("%d %d %d", diff.h, diff.m, diff.s);
}