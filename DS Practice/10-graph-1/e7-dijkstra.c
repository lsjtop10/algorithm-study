
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 1000
#define N 7

char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};


int graph[N][N] = {
    {   0,   7, INF, INF,   3,  10, INF },
    {   7,   0,   4,  10,   2,   6, INF },
    { INF,   4,   0,   2, INF, INF, INF },
    { INF,  10,   2,   0,  11,   9,   4 },
    {   3,   2, INF,  11,   0, INF,   5 },
    {  10,   6, INF,   9, INF,   0, INF },
    { INF, INF, INF,   4,   5, INF,   0 }
};

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

void print(){
    for(int i =0; i < N; i++){
        if(dist[i] == INF){
            printf(" * ");
        }
        else{
            printf(" %d ", dist[i]);
        }
    }
    
    printf("\n");
}

void dijkstra(int startVNum) {
    dist[startVNum] = 0;

    for (int i = 0; i < N; i++) {
        int s = getMinVertex();
        visited[s] = true;

        // printf("[%c, %d]", vName[s], dist[s]);

        for (int t = 0; t < N; t++) {
            // 아직 안 갔고 갈 수 있는  노드라면
            if (visited[t] == false && graph[s][t] != INF 
                // 프림: 거리 기준이 선택된 노드에서 인접 정점으로 가는 최단거리
                // 다익스트라: 거리 기준이 시작 정점에서 그 정점으로 가는 최단거리
                && dist[s] + graph[s][t] < dist[t]) {
                dist[t] = dist[s] +graph[s][t];
            }
        }

        print();
    }
}

int main(void) {
    init();
    
    dijkstra(0);
}
