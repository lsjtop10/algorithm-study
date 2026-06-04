
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 1000
#define N 7

char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

// clang-format off
int graph[N][N] = {
    {0, 29, INF, INF, INF, 10, INF}, 
    {25, 0, 16, INF, INF, INF, 15}, 
    {INF, 16, 0, 12, INF, INF, 16},
    {INF, INF, 12, 0, 22, INF, 18},  
    {INF, INF, INF, 22, 0, 27, 25}, 
    {10, INF, INF, INF, 27, 0, INF},
    {INF, 15, INF, 18, 25, INF, 0}
};
//clang-format on

bool visited[N];
int dist[N];

void init() {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
}

int getMinVertex() {
    int minVertex = 0;
    int minDist = INF;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false && dist[i] < minDist) {
            minVertex = i;
            minDist = dist[i];
        }
    }

    return minVertex;
}

void prim(int startVNum) {
    dist[startVNum] = 0;

    for (int i = 0; i < N; i++) {
        int vNum = getMinVertex();
        visited[vNum] = true;

        printf("[%c, %d]", vName[vNum], dist[vNum]);

        for (int aNum = 0; aNum < N; aNum++) {
            if (visited[aNum] == false && graph[vNum][aNum] != INF &&
                /*dist[vNum] + */ graph[vNum][aNum] < dist[aNum]) {
                dist[aNum] = /*dist[vNum] +*/graph[vNum][aNum];

                // 자 여기에서 주석친 부분을 활성화하면 바로 다익스트라 알고리즘이 된다.
                // 프림 알고리즘은 현재까지 만들어진 트리 전체와 '인접 정점'사이의 최단거리 유지. 
                // 한 노드가 추가됨으로써 업데이트되는 최단거리를 이 루프에서 계산한다. 
            }
        }
    }
}

int main(void) {
    init();
    prim(2);
}
