#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char element;

typedef struct Node 
{
    element data;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct{
    Node* H;
    Node* T;
    int size;
}DListType;

Node* makeNode(element e){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->prev = node->next = NULL;
}

void init(DListType* dl){
    dl->H = makeNode(0);
    dl->size = 0;
    dl->T = makeNode(0);

    dl->H->next = dl->T;
    dl->T->prev = dl->H;
}

bool isEmpty(DListType* dl){
    return dl->size == 0;
}

void insertFirst(DListType* dl, element e){
    Node* head = dl->H;
    Node* node = makeNode(e);

    node->prev = head;
    node->next = head->next;

    head->next->prev = node;
    head->next = node;
}

void insertLast(DListType* dl, element e){
    Node* tail = dl->T;
    Node* node = makeNode(e);

    node->prev = tail->prev;
    node->next = tail;

    tail->prev->next = node;
    tail->prev = node;
}

void insert(DListType* dl, element e, int pos){
    //simple-linked-list와 마찬가지로 가장 마지막 노드 뒷단에도 
    if(pos < 0 || pos > dl->size + 1){
        printf("Invalid Positon\n");
        return;
    }

    Node* p = dl->H;

    for(int i = 0; i < pos - 1; i++){
        p = p->next;
    }

    Node* node = makeNode(e);

    node->prev = p;
    node->next = p->next;

    p->next->prev = node;
    p->next = node;

    dl->size++;
}

element delete(DListType* dl, int pos){
    if(isEmpty(dl)){
        printf("Empty");
    }

    if(pos < 0 || pos > dl->size){
        printf("Invalid Position");
        return 0;
    }

    // 삭제할 노들를 가리키는 
    Node* p = dl->H;

    for(int i = 0; i < pos; i++){
        p = p->next; 
    }

    element data = p->data;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    dl->size--;
    free(p);
    return data;
}

void print(DListType* dl){
    for(Node* p = dl->H->next; p != dl->T; p = p->next ){
        printf("[%c]", p->data);
        if(p->next != dl->T){printf("<-->");}
    }
    printf("\n");
}


int main(){
    DListType dl;
    init(&dl);

    insert(&dl, 'A',1);
    insert(&dl, 'B',1);
    insert(&dl, 'C',3);
    insert(&dl, 'D',2);
    insert(&dl, 'E',6);
    print(&dl);
 
    printf("del [%c]\n", delete(&dl, 1));
    print(&dl);

    getchar();
}