#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_DEQUEUE_SIZE 10

typedef char element;
typedef struct DequeueType{
    element arr[MAX_DEQUEUE_SIZE];
    int front;
    int rear;

}DequeueType;

int getNextIdx(int i){
    // mod 연산 특
    // 0~n-1 순환함. 이는 환형 큐에 찰떡인 특징..
    return (i + 1) % MAX_DEQUEUE_SIZE;
}

// int getPrevIdx(int i){
//     // mod연산한 값이 0 -> n-1로 가려면 0일 때 n이 돼야 함.
//     // 어차피 mod연산 중에 넘치는 건 다 짤리니 아래 식이면 가능
//     return (i - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
// }

void init(DequeueType* q){
    q->front = q->rear = 0;
}

bool isFull(DequeueType *q){
    return q->front == getNextIdx(q->rear);
}

bool isEmpty(DequeueType* q){
    return q->front == q->rear;
}

void enqueue(DequeueType* q, element e){
    if(isFull(q)){
        printf("Overflow \n");
        return;
    }

    q->rear = getNextIdx(q->rear);
    q->arr[q->rear] = e;
}

element dequeue(DequeueType* q){
    if(isEmpty(q)){
        printf("Empty \n");
        return -1;
    }

    q->front = getNextIdx(q->front);
    element e = q->arr[q->front];
    return e;
}

element peek(DequeueType* q){
        if(isEmpty(q)){
        printf("Empty \n");
        return -1;
    }

    return q->arr[getNextIdx(q->front)];
}


int main(){
    DequeueType q;
    init(&q);

    dequeue(&q);
    init(&q);

    enqueue(&q,'A');
    enqueue(&q,'B');
    enqueue(&q,'C');
    enqueue(&q, 'D');
    enqueue(&q, 'E');
    enqueue(&q, 'F');
    enqueue(&q,'G');
    enqueue(&q, 'H');
    enqueue(&q, 'I');
    enqueue(&q, 'J');
    init(&q);

    for(int i = 0; i < 9; i++){
        enqueue(&q, i + '0');
    }
    for(int i = 0; i < 2; i++){
       dequeue(&q);
    }
    for(int i = 0; i < 2; i++){
       enqueue(&q, i + '0');
    }

    for(int i = 0; i < 9; i++){
        printf("%c ", dequeue(&q));
    }

}