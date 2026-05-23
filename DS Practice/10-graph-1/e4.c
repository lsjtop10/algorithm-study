#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjVertex {
    char name;
    struct AdjVertex* next;
} AdjVertex;

typedef struct Vertex {
    char name;
    bool isVisted;
    struct Vertex* next;

    AdjVertex* adjHead;
} Vertex;

typedef struct {
    Vertex* head;
} GraphType;

void initGraph(GraphType* g) { g->head = NULL; }

void makeVertex(GraphType* g, char name) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));

    v->name = name;
    v->isVisted = false;
    v->adjHead = NULL;
    v->next = NULL;

    Vertex* p = g->head;
    if (p == NULL) {
        g->head = v;
        return;
    }

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = v;
}

// TODO: 탐색실패 예외처리
Vertex* findVertex(GraphType* g, char name){
    Vertex* p = g->head;

    while (p->name != name){
        p = p->next;
    }
    return p;
    
}

void makeAdjacentVertex(Vertex* v, char name){
    AdjVertex* adjV = (AdjVertex*)malloc(sizeof(AdjVertex));

    adjV->name = name;
    adjV->next = NULL;

    AdjVertex* p = v->adjHead;
    if(p == NULL){
        v->adjHead = adjV;
        return;
    }

    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = adjV;
    
}

void insertEdge(GraphType* g, char v1, char v2){
    //u 탐색
    Vertex* v = findVertex(g, v1);
    //insert last v
    makeAdjacentVertex(v, v2);

    // v탐색
    v = findVertex(g, v2);
    // insert last u
    makeAdjacentVertex(v, v1);
}

void print(GraphType* g){
    Vertex* p = NULL;
    AdjVertex* q = NULL;

    for(p = g->head; p != NULL; p=p->next){
        printf("[%c] : ", p->name);
        for(q = p->adjHead; q != NULL; q=q->next){
            printf("[%c]", q->name);
        }
           printf("\n");
    }
    
    printf("\n");
}

// 정점도 연결리스트
// 각 정점마다 인접 정점도 연결리스트
// 인접 리스트
int main() {
    GraphType g;
    initGraph(&g);

    makeVertex(&g, 'A');
    makeVertex(&g, 'B');
    makeVertex(&g, 'C');
    makeVertex(&g, 'D');
    makeVertex(&g, 'E');
    makeVertex(&g, 'F');
    makeVertex(&g, 'G');
    makeVertex(&g, 'H');

    insertEdge(&g, 'A', 'B');
    insertEdge(&g, 'A', 'C');
    insertEdge(&g, 'B', 'D');

    insertEdge(&g, 'C', 'D');
    insertEdge(&g, 'C', 'E');

    insertEdge(&g, 'D', 'F');

    insertEdge(&g, 'E', 'G');
    insertEdge(&g, 'E', 'H');

    insertEdge(&g, 'G', 'H');

    print(&g);

}