#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjVertex
{
    char aName;
    struct AdjVertex* next;
}AdjVertex;

typedef struct Vertex
{
    char vName;
    int isVisit;
    AdjVertex* aHead;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex *vHead;
}GraphType;

void initGraph(GraphType *G)
{
    G->vHead = NULL;
}

void appendVertex(GraphType *G, char vName)
{
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = false;
    v->aHead = NULL;
    v->next = NULL;
    
    Vertex *p = G->vHead;
    
    if(p == NULL)
        G->vHead = v;
    else
    {
        while(p->next != NULL)
            p = p->next;          
        p->next = v;    
    }
}

Vertex* findVertex(GraphType *G, char vName)
{
    Vertex *p = G->vHead;
    
    while(p->vName != vName)
        p = p->next;
    
    return p;    
}

void makeAdjacentVertex(Vertex *v, char aName)
{
    AdjVertex *a = (AdjVertex *)malloc(sizeof(AdjVertex));
    a->aName = aName;
    a->next = NULL;
    
    AdjVertex *p = v->aHead;
    
    if(p == NULL)
        v->aHead = a;
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = a;    
    }
}

void insertEdge(GraphType *G, char v1, char v2)
{
    Vertex *v = findVertex(G, v1);
    makeAdjacentVertex(v, v2);
    
    v = findVertex(G, v2);
    makeAdjacentVertex(v, v1);
}

void print(GraphType *G)
{
    Vertex *p = NULL;
    AdjVertex *q = NULL;
    
    for(p = G->vHead; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->aHead; q != NULL; q = q->next)
            printf("[%c] ", q->aName);
        printf("\n");    
    }
}

#define N 10
typedef char element;

typedef struct QueueType 
{
    int front, rear;
    element queue[N];
}QueueType;

void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
	return Q->front == Q->rear;
}

int isFull(QueueType* Q)
{
	return Q->front == (Q->rear + 1) % N;
}

void enqueue(QueueType* Q, element e)
{
    if(isFull(Q))
        printf("Overflow.\n");
    else
    {
        Q->rear = (Q->rear + 1) % N;
        Q->queue[Q->rear] = e;
    }    
}

element dequeue(QueueType* Q)
{
    if(isEmpty(Q))
    {
        printf("Underflow.\n");
        return -1;
    }

    Q->front = (Q->front + 1) % N;
	return Q->queue[Q->front];
}

void BFS(GraphType *G, char vName)
{
    Vertex* v = findVertex(G, vName);
    AdjVertex* a = NULL;
    
    QueueType Q;
    initQueue(&Q);
    
    v->isVisit = true;
    printf("[%c] ", v->vName);
    enqueue(&Q, v->vName);
    
    while(!isEmpty(&Q))
    {
        v = findVertex(G, dequeue(&Q));
        
        for(a = v->aHead; a != NULL; a = a->next)
        {
            // 인접 정점은 이름밖에 없어서 결국 찾아야 하네..
            // 포인터로 연결하면 탐색은 빠르겟으나 참조 구조가 복잡해져서 메모리 관리에 어려움을 겪을 수도 ..
            v = findVertex(G, a->aName);
            if(v->isVisit == false)
            {
                v->isVisit = true;
                printf("[%c] ", v->vName);
                enqueue(&Q, v->vName);
            }
        }
    }
}

int main()
{
    GraphType G;
    initGraph(&G);

    appendVertex(&G, 'A'); appendVertex(&G, 'B'); appendVertex(&G, 'C'); 
    appendVertex(&G, 'D'); appendVertex(&G, 'E'); appendVertex(&G, 'F');
    appendVertex(&G, 'G'); appendVertex(&G, 'H');

    insertEdge(&G, 'A', 'B'); insertEdge(&G, 'A', 'C'); insertEdge(&G, 'B', 'D'); 
    insertEdge(&G, 'C', 'D'); insertEdge(&G, 'C', 'E'); insertEdge(&G, 'D', 'F'); 
    insertEdge(&G, 'E', 'G'); insertEdge(&G, 'E', 'H'); insertEdge(&G, 'G', 'H');

    print(&G); printf("\n");

    printf("BFS : "); BFS(&G, 'A');

}