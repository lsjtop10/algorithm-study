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

void init(DequeType* d){
    d->front = d->rear = 0;
}

int isEmpty(DequeType* d){
    return d->front == d->rear; 
}

int isFull(DequeType* d){
    //Rear의 다음 index가 front와 같은가? 
    return d->front == (d->rear + 1) % N;
}

void addFront(DequeType* d, element e){
    if(isFull(d)){
        printf("Overflow");
    }else{
        d->arr[d->front] = e;
        
        //
        d->front = (d->front - 1 + N) % N; 
    }
}

void addRear(DequeType* d, element e){ //enqueue, push
    if(isFull(d)){
        printf("Overflow \n");
    }else{

        d->rear = (d->rear + 1) % N;
        d->arr[d->rear] = e;
    }
}

//dequeue
element deleteFront(DequeType* d){
    if(isEmpty(d)){
        printf("empty");
    }

    d->front = (d->front + 1) % N;
    return d->arr[d->front];
}

element deleteRear(DequeType* d){
    if(isEmpty(d)){
        printf("empty");
    }

    element e = d->arr[d->rear];
    // 0에서 이전 index를 구할 때 -1이 아니라 N-1이 나올 수 있도록
    // d->rear - 1에 N을 더해준다. 이를 다시 N으로 mod연산을 해서 
    // 넘친 부분을 잘라내고 0부터 n - 1 범위로 맞춰준다.
    d->rear = (d->rear - 1 + N) % N;
    return e;
}

element getFront(DequeType* d){
    if(isEmpty(d)){
        printf("isEmpty \n");
        return;
    }

    return d->arr[(d->front + 1) % N];
}

element getRear(DequeType* d){
    if(isEmpty(d)){
        printf("isEmpty \n");
        return;
    }

    return d->arr[d->rear];
}


void print(DequeType* d){
    printf("Front : %d, Rear : %d \n", d->front, d->rear);

    if(isEmpty(d)){
        printf("Queue is empty.");
        return;
    }


    int i = d->front;
    // i == rear이면 반복문에서 rear 다음 원소 즉 유효하지 않은 인덱스를 참조 
    // i < rear일 때 다음 원소 출력 
    while( i != d->rear){
        i = (i + 1) % N;
        printf("[%c] ", d->arr[i]);
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
    DequeType d;

}