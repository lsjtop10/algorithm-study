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

int getPrevIdx(int i){
    // mod연산한 값이 0 -> n-1로 가려면 0일 때 n이 돼야 함.
    // 어차피 mod연산 중에 넘치는 건 다 짤리니 아래 식이면 가능
    return (i - 1 + MAX_DEQUEUE_SIZE) % MAX_DEQUEUE_SIZE;
}

void init(DequeueType* q){
    q->front = q->rear = 0;
}

bool isFull(DequeueType *q){
    return q->front == getNextIdx(q->rear);
}

bool isEmpty(DequeueType* q){
    return q->front == q->rear;
}

void addRear(DequeueType* q, element e){
    if(isFull(q)){
        printf("Overflow \n");
        return;
    }

    q->rear = getNextIdx(q->rear);
    q->arr[q->rear] = e;
}

void addFront(DequeueType* q, element e){
    if(isFull(q)){
        printf("Overflow \n");
        return;
    }

    q->arr[q->front] = e;
    q->front = getPrevIdx(q->front);

}

element removeRear(DequeueType* q){
    if(isEmpty(q)){
        printf("Empty \n");
        return -1;
    }


    element e = q->arr[q->rear];
    q->rear = getPrevIdx(q->rear);
    return e;
}

element removeFront(DequeueType* q){
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

    removeRear(&q);
    init(&q);

    addRear(&q,'A');
    addRear(&q,'B');
    addRear(&q,'C');
    addRear(&q, 'D');
    addRear(&q, 'E');
    addRear(&q, 'F');
    addRear(&q,'G');
    addRear(&q, 'H');
    addRear(&q, 'I');
    addRear(&q, 'J');
    init(&q);

    for(int i = 0; i < 9; i++){
        addRear(&q, i + '0');
    }
    for(int i = 0; i < 2; i++){
       removeRear(&q);
    }
    for(int i = 0; i < 2; i++){
       addRear(&q, i + '0');
    }

    for(int i = 0; i < 9; i++){
        printf("%c ", removeRear(&q));
    }

    init(&q);

    addFront(&q,'A');
    addFront(&q,'B');
    addFront(&q,'C');
    addFront(&q, 'D');
    addFront(&q, 'E');
    addFront(&q, 'F');
    addFront(&q,'G');
    addFront(&q, 'H');
    addFront(&q, 'I');
    addFront(&q, 'J');
    init(&q);

    for(int i = 9; i >= 1; i--){
        addFront(&q, i + '0');
    }
    for(int i = 0; i < 2; i++){
       removeFront(&q);
    }
    for(int i = 1; i <= 2; i++){
       addFront(&q, i + '0');
    }

    for(int i = 0; i < 9; i++){
        printf("%c ", removeFront(&q));
    }

}