#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DoBFS(int start);

void DoBFS(int start){
    queue<int> tesk;
    tesk.push(start);
    visited[start] = true;

    while (!tesk.empty()) {
        int current = tesk.front();
        tesk.pop();

        
        for (auto e : A[current]) {
            if (visited[e]) {continue;}
            
            visited[e] = true;
            tesk.push(e);
        }
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


    DoBFS(1);

    int result = 0;
    for (auto e : visited ) {
        if(e) result++;
    }

    
    cout << result - 1;
    
    return 0;
}
