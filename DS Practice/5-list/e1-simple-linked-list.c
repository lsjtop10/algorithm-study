#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char element;

typedef struct Node
{
    element data;
    struct Node* next;
    
} Node;

typedef struct {
    Node* head;
    int size;
}ListType;

void init(ListType* l){
    l->head = NULL;
    l->size = 0;
}

bool isEmpty(ListType* l){
    return l->size == 0;
} 

Node* makeNode(element e){
    //null ckeck 필요.
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;

    return node;
}

void insertFirst(ListType* l, element e){
    Node* node = makeNode(e);

    // 이 두 줄이 핵심임
    // head가 가리키는 노드는 새로 생성된 노드가 이제 가리킬 노드임.  
    node->next = l->head;
    l->head = node;

    l->size++;
}

element deleteFirst(ListType* l){
    
    if(isEmpty(l)){
        printf("Empty.\n");
        return '\0';
    }

    Node* p = l->head;
    element data = p->data;

    l->head = p->next;
    free(p);

    return data;
}

// Pos가 어떤 의미인지 잘 봐둘 것
// 여기에서 pos는 1 based index임.
// Pos는 삽입된 노드의 위치임. Pos == 3 이면 3번째 자리에 들어가고 나머지 노드는 뒤로 미룸.
// TODO: 버그 있음. 수정 요망
void insertPositon(ListType* l, element e, int pos){
    
    //맨 뒤 노드의 1번째 뒤에도 들어갈 수 있음 
    if(pos <= 0 || pos > l->size + 1){
        printf("Invlaid Pos\n");
        return;
    }

    if(pos == 1){
        insertFirst(l, e);
        return;
    }

    Node* node = makeNode(e);
    Node* p = l->head;

    for(int i = 2; i < pos; i++){
        p = p->next;
    }

    node->next = p->next;
    p->next = node;
    l->size++;
}

element deletePosion(ListType* l, int pos){
    
    if(isEmpty(l)){
        printf("Empty.\n");
        return '\0';
    }

    if(pos <= 0 || pos > l->size){
        printf("Invlaid Pos \n");
        return '\0';
    }

    if(pos == 1){
        return deleteFirst(l);
    }

    //삭제할 노드의 이전 노드를 가리키는 포인터
    Node* p = l -> head;
    for(int i = 2; i < pos; i++){
        p = p->next;
    }

    //삭제할 노드를 가리키는 포인터
    Node* q = p->next;
    element data = q->data;
    p -> next = q->next;
    free(q);

    l->size--;

    return data;
}

void print(ListType* l){
    // 커서 역할을 하는 변수는 p,q,r을 주로 쓸 것임: 네이밍 컨벤션
    // head 포인터는 첫 번째 노드임.
    Node* p = l->head;

    while (p != NULL){
        printf("[%c]", p->data);
        if(p->next != NULL){
            printf(" -> ");
        }
        
        p = p->next;
    }

    printf("\n");
}

int main(){
    ListType l;
    init(&l);

    insertFirst(&l, 'a');
    insertFirst(&l, 'b');
    insertFirst(&l, 'c');
    getchar();

    insertPositon(&l, 'd', 4);
    insertPositon(&l, 'e', 3);    
    print(&l);

    getchar();
    deletePosion(&l, 2);
    print(&l);

    getchar();
    deletePosion(&l, 5);
    print(&l);

}