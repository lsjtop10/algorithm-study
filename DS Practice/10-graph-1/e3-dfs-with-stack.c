#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define N 8 // 정점의 개수
#define D 4 // 정점의 최대 차수

typedef char element;

//___type은 우리가 만들 최종 자료구조를 정의한 것임
typedef struct {
    element arr[MAX_STACK_SIZE];
    int top;
} StackType;

void stack_init(StackType* s) {
    // 일반적으로는 -1로 놓고 시작한다.
    s->top = -1;
}

int isEmpty(StackType* s) { return s->top == -1; }

int isFull(StackType* s) { return s->top >= MAX_STACK_SIZE - 1; }

void printStack(StackType* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("|  %c  |\n", s->arr[i]);
        printf("-----\n");
    }
}

// 이미 주소를 받았으니까 그냥 받은 주소를 넘기면 됨
void push(StackType* s, element e) {
    if (isFull(s)) {
        printf("Overflow!");
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

element peek(StackType* s) {
    if (isEmpty(s)) {
        printf("empty\n");
    }

    return s->arr[s->top];
}

element pop(StackType* s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return -1;
    }

    element e = s->arr[s->top];
    s->top--;
    return e;
}

typedef struct {
    char name;
    int adj[D];
    int adjCount;
} Vertex;

Vertex Graph[N] = {
    {'A', {1, 2}, 2},
    {'B',
     {
         0,
         3,
     },
     2},
    {'C', {0, 3, 4}, 3},
    {'D', {1, 2, 5}, 3},
    {'E', {2, 6, 7}, 3},
    {'F', {3}, 1},
    {'G',
     {
         4,
         7,
     },
     2},
    {'H', {4, 6}, 1},
};

void iDFS(bool visited[], int s) {
    StackType stack;
    stack_init(&stack);

    visited[s] = true;
    push(&stack, s);
    printf("[%c] ", Graph[s].name);

    while (!isEmpty(&stack)) {
        s = peek(&stack);
        bool isfoundUnvisited = false;

        for (int i = 0; i < Graph[s].adjCount; i++) {
            int t = Graph[s].adj[i];

            // visited false이면 방문
            if (!visited[t]) {

                push(&stack, t);
                printf("[%c] ", Graph[t].name);
                
                visited[t] = true;

                isfoundUnvisited = true;
                break;
            }

        }

        // 이게 핵심 로직이다.
        // 더 방문할 수 없는 노드가 없다면(=막다른 노드라면) 
        // 1단계 위로 올라간다. 만약에 그 노드에서 방문할 수 있는 다른 노드가 있으면 그냥 올라가고
        // 아니면 한 단계 올라간다. 이렇게 거슬러 올라가다가 탐색 가능한 노드가 있으면 그 길로 갈 것이다.
        if (!isfoundUnvisited) {
            pop(&stack);
        }
    }
}

int main() {
    bool visited[N] = {false};
    iDFS(visited, 1);
}