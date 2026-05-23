#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct Edge {
    char v1, v2;
    int weight;
    struct Edge* next;
} Edge;

typedef struct AdjVertex {
    char name;
    Edge* e;
    struct AdjVertex* next;
} AdjVertex;

typedef struct Vertex {
    char name;

    bool isVisit;
    AdjVertex* aHead;
    struct Vertex* next;
} Vertex;

typedef struct GraphType{
    Vertex* vHead;
    Edge* eHead;
    int vCount, eCount
} GraphType;

int vertices[N] = {-1};

void initGraph(GraphType* g) {
    g->vHead = NULL;
    g->eHead = NULL;

    g->vCount = g->eCount = 0;
}

void makeVertex(GraphType* g, char vName) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->name = vName;
    v->isVisit = false;
    v->aHead = NULL;
    v->next = NULL;

    Vertex* p = g->vHead;

    g->vCount++;

    if (p == NULL)
        g->vHead = v;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = v;
    }
}

Vertex* findVertex(GraphType* g, char name) {
    Vertex* p = g->vHead;

    while (p->name != name)
        p = p->next;

    return p;
}

void makeAdjacentVertex(Vertex* v, char aName, Edge* e) {
    AdjVertex* a = (AdjVertex*)malloc(sizeof(AdjVertex));
    a->name = aName;
    a->next = NULL;
    a->e = e; // 추가됨

    AdjVertex* p = v->aHead;

    if (p == NULL)
        v->aHead = a;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = a;
    }
}

void insertEdge(GraphType* G, char v1, char v2, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v1 = v1;
    e->v2 = v2;
    e->weight = weight;
    e->next = NULL;

    G->eCount++;

    Edge* p = G->eHead;

    if (p == NULL)
        G->eHead = e;
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = e;
    }

    Vertex* v = findVertex(G, v1);
    makeAdjacentVertex(v, v2, e);

    v = findVertex(G, v2);
    makeAdjacentVertex(v, v1, e);
}

void print(GraphType* G) {
    Vertex* p = NULL;
    AdjVertex* q = NULL;

    for (p = G->vHead; p != NULL; p = p->next) {
        printf("[%c] : ", p->name);
        for (q = p->aHead; q != NULL; q = q->next)
            printf("[%c, %d] ", q->name, q->e->weight);
        printf("\n");
    }
}

void selectionSort(GraphType* g, Edge* edges[]) {
    Edge* p = g->eHead;

    for (int i = 0; i < g->eCount; i++) {
        edges[i] = p;
        p = p->next;
    }

    for (int i = 0; i < g->eCount - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < g->eCount; j++) {
            if (edges[minIdx]->weight > edges[j]->weight) {
                minIdx = j;
            }
        }

        Edge* tmp = edges[minIdx];
        edges[minIdx] = edges[i];
        edges[i] = tmp;

        printf("\n");
    }

    for (int i = 0; i < g->eCount; i++) {
        printf("[%c%c%d]", edges[i]->v1, edges[i]->v2, edges[i]->weight);
    }
}

int find(char vName) {
    int vNum = vName - 'A';

    // 그냥 return하면 안 되고 -1이 아닐 때까지 = 루트가 아닌 동안 반복 필요함
    // 그래서 자기 자신이 root이면 그냥 자기 자신을 return한다.
    while (vNum != -1) {
        vNum = vertices[vNum];
    }

    return vNum;
}

int union_(char vName1, char vName2) { vertices[vName1 - 'A'] = vName2 - 'A'; }

void kruskal(GraphType* G, Edge* edges[]) {
    int eCnt = 0;
    int idx = 0;

    int groupV1, groupv2;
    Edge* p;

    // 왜 eCont - 1?
    while (eCnt < G->eCount - 1) {
        p = edges[idx];

        // find
        groupV1 = find(p->v1);
        groupv2 = find(p->v2);

        // uninon and choice
        if (groupV1 != groupv2) {
            eCnt++;
            union_(p->v1, p->v2);
            printf("%d. [%c%c%d]\n", eCnt, p->v1, p->v2, p->weight);
        }

        idx++;
    }
}

int main() {
    GraphType G;
    initGraph(&G);
    // 프림 알고리즘은 힙트리? 사실 힙에서 하나씩 빼는 방법이 괜찮아보인는데...
    // 프림은 트리와 인접한 정점 중에서 가장 작은 정점을 꺼내야 하므로 
    // 모든 정점을 한 번에 정렬하기보다 그냥 우선순위 큐 쓰는 것이 낫지 않을까?
    makeVertex(&G, 'A');
    makeVertex(&G, 'B');
    makeVertex(&G, 'C');
    makeVertex(&G, 'D');
    makeVertex(&G, 'E');
    makeVertex(&G, 'F');
    makeVertex(&G, 'G');

    insertEdge(&G, 'A', 'B', 29);
    insertEdge(&G, 'A', 'F', 10);
    insertEdge(&G, 'F', 'E', 27);
    insertEdge(&G, 'E', 'D', 22);
    insertEdge(&G, 'D', 'C', 22);
    insertEdge(&G, 'B', 'C', 16);
    insertEdge(&G, 'B', 'G', 15);

    print(&G);
    Edge* edges[N];

    selectionSort(&G, edges);
    kruskal(&G, edges);

    return 0;
}
