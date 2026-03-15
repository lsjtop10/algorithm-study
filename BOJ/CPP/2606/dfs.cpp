#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DoDFS(int start);

void DoDFS(int start){
    visited[start] = true;

    for (auto node : A[start]) {
        if (visited[node]) {continue;}
        DoDFS(node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int NumOfComputers = 0;
    int NumOfEdges = 0;

    cin >> NumOfComputers;
    cin >> NumOfEdges;

    A = vector<vector<int>>(NumOfComputers + 1, vector<int>(0));
    visited = vector<bool>(NumOfComputers + 1, false);
    
    //입력받기
    for(int i = 0; i < NumOfEdges; i++){
        int s;
        int e;

        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }


    DoDFS(1);

    int result = 0;
    for (auto e : visited ) {
        if(e) result++;
    }

    
    cout << result - 1;
    
    return 0;
}
