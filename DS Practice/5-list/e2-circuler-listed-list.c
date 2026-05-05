#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char element;

typedef struct Node
{
    element data;
    struct Node* next;
    
}Node;

typedef struct ListType
{
    struct Node* tail;
    int size;
}ListType;

void init(ListType* L){
    L->tail = NULL;
    L->size = 0;
}

Node* makeNode(element e){
    //null ckeck 필요.
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;

    return node;
}

bool isEmpty(ListType* l){
    return l->size == 0;
} 

void insertLast(ListType* L, element e){
    Node* node = makeNode(e);
    if(isEmpty(L)){
        L->tail = node;
        L->tail->next = node;
    }else{
        // 내가 먼저 가리키고
        // 남이 먼저 나를 가리키게 한다.
        node->next= L->tail->next; 

        L->tail->next = node;
        L->tail = node;
        //만약 순서가 반대로 되면 어떻게 될까?
    }

    L->size++;

}
    
void inserFirst(ListType* L, element e){
    Node* node = makeNode(e);
    if(isEmpty(L)){
        L->tail = node;
        L->tail->next = node;
    }else{
        // 내가 먼저 가리키고
        // 남이 먼저 나를 가리키게 한다.

        node->next= L->tail->next; 

        L->tail->next = node;
        // 만약 순서가 반대로 되면 어떻게 될까?
        // 그러면 새로 추가할 노드가 누구를 가리켜야 할지 알 수 없음.
    }

    L->size++;
}

element deleteFirst(ListType* L){
    if(isEmpty(L)){
        printf("Invlaid operation: Cant' remove a element from the empty list\n");
    }

    Node* del = L->tail->next;
    L->tail->next = del->next;
    
    if(L->size == 1){
        L->tail = NULL;
    }

    L->size--;

}

element deleteLast(ListType* L){
    if(isEmpty(L)){
        printf("Invlaid operation: Cant' remove a element from the empty list\n");
    }

    Node* del = L->tail;
    L->tail->next = del->next;
    
    if(L->size == 1){
        L->tail = NULL;
    }

    L->size--;

}

// deleete 할 때는
// 1개만 있는 경우
// 최소 2개 있는 경우 처리가 다름
// delete first, delete last, print는 직접 만들어 보기. 시험에서 나올 가능성 높음.

int main(){

}
