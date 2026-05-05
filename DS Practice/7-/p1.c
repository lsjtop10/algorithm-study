#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT 100

typedef struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct DListType{
    Node* head;
    Node* tail;
    Node* curser;

}DListType;

Node* makeNode(char data);
void init(DListType* DL);
void insertChar(DListType* DL, char c);
void moveLeft(DListType* DL);
void deleteChar(DListType* DL);
void printText(DListType* DL);
void debug__deleteAllNodes(DListType* DL);

//테스트용 함수. 개발 과정에서 사용.
void debug__deleteAllNodes(DListType* DL){
    Node* current = DL->head;
    Node* next = current->next;

    while (next != NULL){
        free(current);

        current = next;
        next = next->next;
    }

    DL->head->next = DL->tail;
    DL->tail->prev = DL->head;

}

Node* makeNode(char data){
    Node* node = (Node*)malloc(sizeof(Node));
    
    //Node의 next와 prev 포인터 모두 NULL로 초기화
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    
    return node;
}

void init(DListType* DL){
    DL->head = makeNode('\0');
    DL->tail = makeNode('\0');

    if(DL->head == NULL || DL->tail == NULL){
        printf("");
    }

    DL->head->next = DL->tail;
    DL->tail->prev = DL->head;
    // cursor는 오른쪽 노드를 가리켜야 하므로 초기 상태는 tail로 초기화 해야 함.
    DL->curser = DL->tail;
}

void moveLeft(DListType* DL){
    // 제약조건 반영
    // 커서는 반드시 두 글짜 사이의 오른쪽 글짜를 가리켜야 함
    // == 커서는 head가 될 수 없음.
    // == Left로 이동하기 전 현재 커서는 Head의 next node일 수 없음.
    if(DL->curser == DL->head->next){
        // 예외 상황 시 처리 방법이 문제에서는 언급돼 있지 않음.
        // 수업 시간에 활용한 방법 대로 에러 메시지를 출력함.
        printf("Invaild Operation: Can't move curser to the head\n");
        return;
    }

    DL->curser = DL->curser->prev;
}

void moveRight(DListType* DL){
    // 제약조건 반영
    // 커서는 오른쪽 노드를 가리키며 왼쪽과 오른쪽 사이의 위치를 나타냄.
    // tail 위치 뒤로 커서가 갈 수는 없음. 
    // == Right로 이동하기 전 현재 커서는 tail일 수 없음.
    if(DL->curser == DL->tail){
        printf("Invaild Operation: Can't move curser to next the tail\n");
        return;
    }

    DL->curser = DL->curser->next;
}

void insertChar(DListType* DL, char c){
    // 커서 왼쪽에 문자를 넣음
    // 커서가 head일 수는 없음.
    Node* new = makeNode(c);
    
    // 새로운 노드의 다음 노드는 커서
    // 새로운 노드를 먼저 업데이트하고
    new->next = DL->curser;
    new->prev = DL->curser->prev;

    // 그 정보를 이용해서 나머지 노드도 업데이트
    new->prev->next = new;
    new->next->prev = new;
}

void deleteChar(DListType* DL){
    // 삭제할 문자가 없는 경우 == curser 가 head와 첫 번째 노드 사이에 있는 경우 
    // == curser가 head 다음 노드를 가리키는 경우
    // 이 경우 아무 동작도 하지 않음.
    if(DL->curser == DL->head->next){
        return;
    }

    Node* del = DL->curser->prev;

    // del노드를 중심으로 앞 뒤 노드 먼저 업데이트
    del->prev->next = del->next;
    del->next->prev = del->prev;

    // 뒤 노드 삭제
    free(del);

}

void printText(DListType* DL){

    if(DL->curser == DL->head->next){
        printf("|");
    }

    // C++ 언어의 반복자 패턴을 유사하게 이용.
    // 유효한 맨 첫번째부터 tail node 전까지 순회 
    for(Node* it=DL->head->next; it != DL->tail; it=it->next){
        printf("%c", it->data);

        if(it->next == DL->curser){
            printf("|");
        }
    }

    printf("\n");
}


int main(){
    DListType dl;
    init(&dl);
    char input[MAX_INPUT + 1];

    gets_s(input, MAX_INPUT);

    for(int i = 0; i < strlen(input); i++){
        char c = input[i];

        switch (c)
        {
        case '-':
            deleteChar(&dl);
            break;
        case '<':
            moveLeft(&dl);
            break;
        case '>':
            moveRight(&dl);
            break;
        default:
            insertChar(&dl, c);
            break;
        }
    }

    printText(&dl);
}
