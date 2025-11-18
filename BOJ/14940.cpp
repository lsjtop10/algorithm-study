#include <bits/stdc++.h>
using namespace std;

int Row;
int Column;


void BFS(vector<vector<int>> &map, vector<vector<int>> &distances, pair<int,int> start){
    queue<pair<int,int>> tasks;
    distances[start.first][start.second] = 0;
    tasks.push(start);

    // cout << start.first << " " << start.second << "\n";

    vector<pair<int,int>> deltas = {
        {0, -1},
        {0, 1},
        {1, 0},
        {-1, 0},
    };

    while(!tasks.empty()){
        pair<int,int> current = tasks.front();
        tasks.pop();

        for(auto e : deltas){
            int nextR = current.first + e.first;
            int nextC = current.second + e.second;

            
            if (nextR > Row - 1 || nextC > Column - 1
                ||nextR < 0 || nextC <0){
                continue;
            }
            
            if(distances[nextR][nextC] != -1){
                continue;
            }

            tasks.push(pair<int,int>{nextR, nextC});
            distances[nextR][nextC] = distances[current.first][current.second] + 1;
        }

    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> Row >> Column;

    vector<vector<int>> map(Row,vector<int>(Column));
    vector<vector<int>> distances(Row,vector<int>(Column, -1));

    for(int i = 0; i < Row; i++){
        for(int j = 0; j < Column; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                distances[i][j] = -2;
            }
        }
    }
    
    pair<int,int> start = {0,0};
    for(int i = 0; i < Row; i++){
        for(int j = 0; j < Column; j++){
            if(map[i][j] == 2){
                start = {i,j};
                goto EXIT;
            }
        }
    }
EXIT:

    BFS(map,distances,start);
    for(int i = 0; i < Row; i++){
        for(int j = 0; j < Column; j++){
            int val = distances[i][j];
            if ( val == -2){
                cout << 0;
            }else{
                cout << val;
            }

            if(j != Column - 1){
                cout << " ";
            }
        }
        cout << "\n";
    }
}