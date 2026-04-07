// 예제1: 선형큐
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

typedef int element;
typedef struct DequeType{
    element arr[N];
    int front, rear;
}DequeType;

void init(DequeType* q){
    q->front = q->rear = 0;
}

int isEmpty(DequeType* q){
    return q->front == q->rear; 
}

int isFull(DequeType* q){
    //Rear의 다음 index가 
    return q->front == (q -> rear + 1) % N;
}

void addRear(DequeType* q, element e){
    if(isFull(q)){
        printf("Overflow \n");
    }else{
        q->rear = (q->rear + 1) % N;
        q->arr[q->rear] = e;
    }
}

element dequeue(DequeType* q){
    if(isEmpty(q)){
        printf("empty");
    }

    q->front = (q -> front + 1) % N;
    return q->arr[q->front];
}

element peek(DequeType* q){
    return q->arr[(q -> front + 1) % N];
}


void print(DequeType* q){
    printf("Front : %d, Rear : %d \n", q->front, q->rear);

    if(isEmpty(q)){
        printf("Queue is empty.");
        return;
    }


    int i = q -> front;
    // i == rear이면 반복문에서 rear 다음 원소 즉 유효하지 않은 인덱스를 참조 
    // i < rear일 때 다음 원소 출력 
    while( i != q->rear){
        i = (i + 1) % N;
        printf("[%c] ", q->arr[i]);
    }

}

void fibonacci(int n){
    DequeType q;
    init(&q);

    addRear(&q, 0);
    addRear(&q, 1);

    printf(" 0 1 ");

    for(int i = 2; i <= n; i++){
        element pp = dequeue(&q);
        element p = peek(&q);
        element now = pp + p;
        addRear(&q, now);

        printf("%d ", now);
    }
}

int main(){


    int n;
    scanf("%d", &n);

    fibonacci(n);
}