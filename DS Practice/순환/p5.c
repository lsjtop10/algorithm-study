#include <stdio.h>
#include <stdlib.h>

void hanoi(int num, char from, char via, char to){
    if(num == 1){
        printf("%c %c\n", from, to);
        return;
    }

    hanoi(num - 1, from, to, via);
    printf("%c %c\n", from, to);
    hanoi(num - 1, via, from, to);

}

int main(){
    int num;
    scanf("%d", &num);

    hanoi(num, 'A', 'B', 'C');
}