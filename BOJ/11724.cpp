#include <bits/stdc++.h>
using namespace std;


bool isNodeOfNewElements(vector<bool> &visited, vector<vector<int>> &list, int start){

    if(visited[start]){
        return false;
    }

    queue<int> tasks;
    tasks.push(start);
    visited[start] = true;

    while (!tasks.empty()){
        int current = tasks.front();
        tasks.pop();
        for(int e : list[current]){
            if(!visited[e]){
                tasks.push(e);
                visited[e] = true;    
            }
        }
    }
    
    return true;
    
}

int main(){
    int numV,numE;
    cin >> numV >> numE;

    vector<vector<int>> list(numV + 1);

    for(int i = 0; i < numE; i++){
        int from, to;
        cin >> from >> to;

        list[from].push_back(to);
        list[to].push_back(from);
    }

    vector<bool> visited(numV + 1);
    int res = 0;
    for(int i = 1; i <= numV; i++){
        if(isNodeOfNewElements(visited, list, i)){
            res++;
        }
    }

    cout << res;
}