#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

typedef int element;

//___type은 우리가 만들 최종 자료구조를 정의한 것임
typedef struct {
    element arr[N];
    int top;
} StackType;

void stack_init(StackType* s){
    //일반적으로는 -1로 놓고 시작한다.
    s->top = -1;
}

int isEmpty(StackType* s){
    return s->top == -1;
}

int isFull(StackType* s){
    return s->top >= N - 1;
}

void printStack(StackType* s){
    for(int i = s->top; i >= 0; i--){
        printf("|  %c  |\n", s->arr[i]);
        printf("-----\n");
    }
}

//이미 주소를 받았으니까 그냥 받은 주소를 넘기면 됨
void push(StackType* s, element e){
    if(isFull(s)){
        printf("Overflow!");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

element peek(StackType* s){
    if(isEmpty(s)){
        printf("empty\n");
    }

    return s->arr[s->top];
}

element pop(StackType* s){
    if(isEmpty(s)){
        printf("Empty\n");
        return -1;
    }

    element e = s->arr[s->top];
    s->top--;
    return e;
}

int evaluate(char str[]){
    StackType s;
    stack_init(&s);

    int op1; int op2; int num;
    char c;
    int n = strlen(str);

    for(int i = 0; i < n; i++){
        c = str[i];
        if(isdigit(c)){
            num = c - '0';
            push(&s, num);
        }else if(strchr("+-*/",c)){
            op2 = pop(&s);
            op1 = pop(&s);
            switch (c)
            {
            case '+':
                push(&s, op1 +  op2);
                break;
            case '-':
                push(&s, op1 -  op2);
            case '*':
                push(&s, op1 *  op2);
            case '/':
                push(&s, op1 /  op2);
            }
        }
    }

    return pop(&s);
}

int main(){

    char str[N];
    printf("Input Exper...");
    fgets(str, N, stdin);

    printf("%d\n", evaluate(str));
    return 0;
}



