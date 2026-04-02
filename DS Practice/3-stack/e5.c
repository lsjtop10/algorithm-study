#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define STACK_MAX_ELEMENTS 30

typedef struct {
    int r, c;
} Coor;

typedef Coor element;

//___type은 우리가 만들 최종 자료구조를 정의한 것임
typedef struct {
    element arr[STACK_MAX_ELEMENTS];
    int top;
} StackType;

void init(StackType *s) {
    // 일반적으로는 -1로 놓고 시작한다.
    s->top = -1;
}

int isEmpty(StackType *s) { return s->top == -1; }

int isFull(StackType *s) { return s->top >= N - 1; }

void printStack(StackType *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("|  %c  |\n", s->arr[i]);
        printf("-----\n");
    }
}

// 이미 주소를 받았으니까 그냥 받은 주소를 넘기면 됨
void push(StackType *s, element e) {
    if (isFull(s)) {
        printf("Overflow!");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

element peek(StackType *s) {
    if (isEmpty(s)) {
        printf("empty\n");
    }

    return s->arr[s->top];
}

element pop(StackType *s) {
    if (isEmpty(s)) {
        printf("Empty\n");
    }

    element e = s->arr[s->top];
    s->top--;
    return e;
}

void print(StackType* s){
    printf("[ ");
    for(int i = s->top; i >= 0; i--){
        printf("(%d %d)", s->arr[i].r, s->arr[i].c);
    }
    printf("\n");
}

char map[N][N] = {
    {'1', '1', '1', '1', '1', '1'}, {'0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '1'}, {'1', '1', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '0', 'x'}, {'1', '1', '1', '1', '0', '1'},
};

void printMaze(element e){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(e.r == r && e.c == c){
                printf(" @ ");
            
            }else{
                printf(" %c ", map[r][c]);
            }
        }

        getchar();
    }
}

void insertPos(StackType *s, int r, int c) {
    // 범위 예외처리
    if (r < 0 || c < 0 || r >= N || c >= N) {
        return;
    }

    // 길이 아닌 곳 처리
    // 이미 방문한 곳은 1이 아닌 다른 값으로 채울 예정
    if (map[r][c] != '0' && map[r][c] != 'x') {
        return;
    }

    element pos = {r, c};
    push(s, pos);
}

int main() {
    StackType s;
    init(&s);
    int order = 1;

    insertPos(&s, 1, 0);

    while (!isEmpty(&s)) {
        element e = pop(&s);
        int r = e.r;
        int c = e.c;
        printf("%2d. (%d, %d)", order++, r, c);

        if(map[r][c] == 'x'){
            printf("Success.\n");
            break;
        }else{
            map[r][c] = '.';
            insertPos(&s, r - 1, c);
            insertPos(&s, r, c - 1);
            insertPos(&s, r + 1, c);
            insertPos(&s, r , c + 1);
        }
        
    }
}
