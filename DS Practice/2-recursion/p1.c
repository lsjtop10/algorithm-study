#include <stdio.h>
#include <stdlib.h>

int sum(int input){
    if(input == 1){
        return 1;
    }

    return sum(input - 1) + input;
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", sum(a));

}