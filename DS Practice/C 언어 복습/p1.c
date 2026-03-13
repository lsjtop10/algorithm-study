#include <stdio.h>
#include <stdio.h>

int sum(int input);

int sum(int input){
    int sum = 0;
    for(int i = 1; i <= input; i++){
        sum += i;
    }

    return sum;
}

int main(){
    int ans = 0;
    int input;
    scanf("%d", &input);

    for(int i = 1; i <= input; i++ ){
        ans += sum(i);
    }
    printf("%d", ans);
}