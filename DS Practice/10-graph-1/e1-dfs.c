#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8
char vName[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int graph[N][N] =
    {
        {0, 1, 1, 0, 0, 0, 0, 0}, // A
        {1, 0, 0, 1, 0, 0, 0, 0}, // B
        {1, 0, 0, 1, 1, 0, 0, 0}, // C
        {0, 1, 1, 0, 0, 1, 0, 0}, // D
        {0, 0, 0, 0, 0, 0, 1, 1}, // E
        {0, 0, 0, 1, 0, 0, 0, 0}, // F
        {0, 0, 0, 0, 1, 0, 0, 1}, // G
        {0, 0, 0, 0, 1, 0, 1, 0}  // H
};

void rDfs(bool visited[], int s){
    visited[s] = true;

    printf("[%c] ", vName[s]);

    for(int t = 0; t < N; t++){

        // s에서 t로 가는 간선이 연결돼 있고 t를 방문하지 않았다면
        if(graph[s][t] == 1 && !visited[t]){
            rDfs(visited, t);
        }
    }

}

int main() {
    bool visited[N] = {false};
    rDfs(visited, 2);
}