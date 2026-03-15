#include <bits/stdc++.h>
using namespace std;
constexpr int INF = INT32_MAX;

struct Compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int numV, numE;
    int start;
    
    cin >> numV >> numE;
    cin >> start;

    //graph[시작 노드번호][i번째 끝 노드].{i번째 끝 노드의 번호, 시작부터 i번째 끝 노드까지 가야 하는거리}
    vector<vector<pair<int,int>>> graph = vector<vector<pair<int,int>>>(numV + 1);
    vector<int> distance = vector<int>(numV + 1 , INF);
    
    for(int i = 0; i < numE; i++){
        int from, to, w;
        cin >> from >> to >> w;

        graph[from].push_back(pair<int,int>(to, w));
    }

    //pair<노드 번호, 탐색 시작 노드부터 해당 노드까지 거리>
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> tasks;
    tasks.push(pair<int,int>(start, 0));
    distance[start] = 0;

    while (!tasks.empty()){
        int current = tasks.top().first;
        tasks.pop();

        for(int i = 0; i < graph[current].size(); i++){
            pair<int,int> next = graph[current][i];

            if(distance[current] + next.second < distance[next.first]){
                distance[next.first] = distance[current] + next.second;
                tasks.push(pair<int,int>{next.first, distance[next.first]});
            }
        }
    }

    for(int i = 1; i < numV + 1; i++){
        if(distance[i] == INF){
            cout << "INF" << "\n";
            continue;
        }

        cout << distance[i] << "\n";
    }
    
}