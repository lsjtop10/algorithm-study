#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int BLACK = 1;
const int WHITE = 0;
const int MAX = 1000000;
int main(){
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);

    int width, height;
    cin >> height >> width;

    vector<vector<int>> data;

    /*
    문제에서 입력이 행 단위로 들어오기 때문에
    vector를 사용할 때 첫 번째 index가 세로 방향
    두 번째 index를 가로 방향을 하는 것이 자연스럽다.
    */
    for(int i = 0; i < height; i++){
        string input;
        cin >> input;

        vector<int> row;
        for(int j = 0; j < width; j++){
            
            if(input[j] == 'W'){
                row.push_back(WHITE);
            }else{
                row.push_back(BLACK);
            }
        }
        data.push_back(row);
    }
    

    int minCnt = MAX; 

    //여기도 마찬가지로 아래와 같이 쓰면 인덱스가 잘못돼서 에러가 난다
    //그리고 반복 범위도 실수 했는데 적어도 1번 이상은 반복해야 하기 때문에 범위에 1을 더애줘야 한다.
    /*
        for(int i = 0; i < width - 8; i++){
        for(int j = 0; j < height - 8; j++){
    */

    for(int i = 0; i < height - 8 + 1; i++){
        for(int j = 0; j < width - 8 + 1; j++){
            
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    // if (data[i+k+1][j+l+1] == data[i+k][j+l]) cnt++;
                    // 위 코드와 같은 판별 구조는 자기 자신과 오른쪽 아래 칸이 같은가만 확인한다.
                    // 체스판의 색은 짝수/홀수에 따라 결정되므로 위와 같은 로직으로는 판별 불가하다.
                    int expected = (k + l) % 2 ? 0: 1; 

                    if(data[i + k][j + l] != expected){
                        cnt++;
                    }
                }
            }

            minCnt = min(minCnt, cnt);

            cnt = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    int expected = (k + l) % 2 ? 1: 0; 

                    if(data[i + k][j + l] != expected){
                        cnt++;
                    }
                }
            }

            minCnt = min(minCnt, cnt);
        }
    }

    cout << minCnt;
}
