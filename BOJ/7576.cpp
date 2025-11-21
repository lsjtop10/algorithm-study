#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;

    cin >> col >> row;
    vector<vector<int>> map(row,vector<int>(col,0));

    int rest = 0;
    queue<pair<int,int>> myQueue;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int input;
            cin >> input;
            if(input != -1){
                rest++;
            }
            if(input == 1){
                myQueue.push({i,j});
            }
            map[i][j] = input;
        }
    }

    int res = 1;

    //BFS

    vector<pair<int,int>> deltas{
        {-1,0},
        {1,0},
        {0,-1},
        {0,1},
    };

    while(!myQueue.empty()){
        pair<int,int> current = myQueue.front();
        myQueue.pop();
        rest--;
        
        for(pair<int,int> e: deltas){
            pair<int,int> next = {
                current.first + e.first,
                current.second + e.second
            };

            //next의 경계 조건
            if(next.first < 0 || next.second < 0 ||
                next.first >= row || next.second >= col || 
                map[next.first][next.second] == -1){
                    continue;
            }

            //업데이트하지 않을 조건
            if(map[next.first][next.second] != 0 && 
               map[next.first][next.second] <= map[current.first][current.second]  + 1){
                continue;
            }

            map[next.first][next.second] = map[current.first][current.second] + 1; 
            myQueue.push({next.first,next.second});
            res = map[current.first][current.second] + 1;
        
        }
    }

    cout << (rest == 0 ? res - 1 : -1);
}