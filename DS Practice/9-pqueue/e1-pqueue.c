#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20

typedef int element;

void swap(element* e1, element* e2){
    element* tmp = e1;
    e1 = e2;
    e2 = tmp;
}

typedef struct HeapType {
    element heap[MAX_STACK_SIZE];
    int heapSize;
} HeapType;

void init(HeapType* h) { h->heapSize = 0; }

bool isEmpty(HeapType* h) { return h->heapSize == 0; }

bool isFull(HeapType* h) { return h->heapSize == MAX_STACK_SIZE - 1; }

void upHeap(HeapType* h) {
    // 반복문 구현? => 적중
    int i = h->heapSize;//마지막 노드 가리킴
    element key = h->heap[i];

    // 부모가 존재 && 삽입된 키가 부모보다 크면
    while ((i != 1) && (key > h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    // 이게 왜 필요할까?
    // -> 반복문이 끝나면 i == 1이거나 key가 부모보다 작거나 같은 큰 i가 반환됨.
    // 그 위치가 실제 i
    h->heap[i] = key;
}

void upHeapRec(HeapType* h, int idx) {
    if(idx == 1 || idx > h->heapSize ){
        return;
    }

    int parent = idx / 2;

    if(h->heap[idx] > h->heap[parent]){
        swap(&h->heap[idx], &h->heap[parent]);
        upHeapRec(h, parent);
    }

}


void downHeap(HeapType* h) {
    int parent = 1;
    int child = 2; // 자식 노드르 1개만 했네? 오른쪽은 어떻게? => child는 애초에
                   // 왼쪽부터 조사.
    element key = h->heap[parent];

    // 부등호 방향 조심.
    // child >= h->heapSize라고 하면 당연히 실행 안 딤.
    while ((child <= h->heapSize)) {

        // 자식 노드 같은 경우 제외? => child가 왼쪽 자식일 때 형재 노드가
        // 무조건 존재하는지 검사함. 마지막 노드가 오른쪽인 경우 : 오른쪽
        // 형재노드의 - 1번째 노드는 왼쪽 형제 => 형제 노드 존재 마지막 노드가
        // 왼쪽 자식인 경우: size - 1 번째 노드는 삼촌 노드의 오른쪽  => 형제
        // 노드 존재.
        //
        // 정리하면 루트 노드의 왼쪽 자식과 오른쪽 자식을 비교해서 가장 큰
        // 자식을 찾는 논리임.
        if ((child + 1 <= h->heapSize) && (h->heap[child + 1] > h->heap[child])) {
            child++;
        }

        if (key >= h->heap[child]) {
            break;
        }

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = key;
}

// 중복을 허용하므로 탐색 작업은 필요 x
void inserItem(HeapType* h, element key) {
    // TODO: isFull ckeck
    if(isFull(h)){
        return;
    }

    // 일단 완전이진트리 맨 뒤에다기 삽입하고 봄
    h->heapSize++;
    h->heap[h->heapSize] = key;
    upHeap(h);
}

element deleteItem(HeapType* h) {
    // TODO: isEmpty check
    if(isEmpty(h)){
        return 0;
    }

    element e = h->heap[1];
    h->heap[1] = h->heap[h->heapSize];

    h->heapSize--;
    downHeap(h);
}

void printHeap(HeapType* h) {
    for (int i = 1; i <= h->heapSize; i++) {
        printf("[%d] ", h->heap[i]);
    }

    printf("\n");
}

void heapSort(HeapType* h ){
// TODO: 
}


int main() {
    HeapType h;
    init(&h);

    inserItem(&h, 9);
    inserItem(&h, 7);
    inserItem(&h, 6);
    inserItem(&h, 5);
    inserItem(&h, 4);
    inserItem(&h, 3);
    inserItem(&h, 2);
    inserItem(&h, 2);
    inserItem(&h, 1);
    inserItem(&h, 3);
    printHeap(&h);

    inserItem(&h, 8);
    printHeap(&h);
}