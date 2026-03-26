#include<stdio.h>
#include<stdlib.h>

#define N 100

typedef char element;

//___type은 우리가 만들 최종 자료구조를 정의한 것임
typedef struct {
    element arr[N];
    int top;
} StackType;

void init(StackType* s){
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

int main(){
    StackType s;
    StackType s2;

    init(&s);
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'D');
    push(&s, 'C');
    printStack(&s);

    printf("After pop() : %c \n", pop(&s));
    printf("\n");
    printStack(&s);

    printf("After peek() : %c \n", peek(&s));
    printf("\n");
    printStack(&s);

}



