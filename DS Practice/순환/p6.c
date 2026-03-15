#include <stdio.h>
#include <stdlib.h>

// a must be grater than b 
int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main(){
    int a;
    int b;

    scanf("%d %d", &a, &b);
    
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    printf("%d", gcd(a, b));
}