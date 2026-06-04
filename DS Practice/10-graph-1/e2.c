#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8 // 정점의 개수
#define D 4 // 정점의 최대 차수

char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

typedef struct {
    char name;
    int adj[D];
    int adjCount;
} Vertex;

// clang-format off
Vertex Graph[N] = {
    {'A', {1, 2},    2},
    {'B', {0, 3},    2},
    {'C', {0, 3, 4}, 3},
    {'D', {1, 2, 5}, 3},
    {'E', {2, 6, 7}, 3},
    {'F', {3},       1},
    {'G', {4, 7},    2},
    {'H', {4, 6},    1}
};
// clang-format on

void rDfs(bool visited[], int s) {
    visited[s] = true;

    printf("[%c] ", Graph[s].name);

    for (int i = 0; i < Graph[s].adjCount; i++) {
        int t = Graph[s].adj[i];

        // s에서 t로 가는 간선이 연결돼 있고 t를 방문하지 않았다면
        if (!visited[t]) {
            rDfs(visited, t);
        }
    }
}

int main() {
    bool visited[N] = {false};
    rDfs(visited, 2);
}