// 예제1: 선형큐
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

typedef char element;
typedef struct DequeType{
    element arr[N];
    int front, rear;
}DequeType;

void init(DequeType* q){
    q->front = q->rear = -1;
}

int isEmpty(DequeType* q){
    return q->front == q->rear; 
}

int isFull(DequeType* q){
    return q->rear == N - 1;
}

void addRear(DequeType* q, element e){
    if(isFull(q)){
        printf("Overflow \n");
    }else{
        q->rear++;
        q->arr[q->rear] = e;
    }
}

element dequeue(DequeType* q){
    if(isEmpty(q)){
        printf("empty");
    }

    q->front++;
    return q->arr[q->front];
}

void print(DequeType* q){
    printf("Front : %d, Rear : %d \n", q->front, q->rear);

    if(isEmpty(q)){
        for(int i = q->front + 1; i <= q->rear; i++){
            printf("[%c]", q->arr[i]);
        }
    }
}

int main(){
    DequeType q;
    init(&q);

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        addRear(&q, rand() % ('Z' - 'A') + 'A');
    }
    print(&q); getchar();

    for (int i = 0; i < 3; i++){
        printf("[%c] ", dequeue(&q));
    }
    printf("\n");
    print(&q); getchar();


    
    for(int i = 0; i < 6; i++){
        addRear(&q, rand() % ('Z' - 'A') + 'A');
    }
    print(&q); getchar();

}