#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct compare{
    //절댓값이 가장 작은 수
    //절댓값이 같으면 음수 우선
    bool operator()(int a, int b){
        //부호가 다르면 음수(작은 수) 우선
        if(abs(a) == abs(b)){
            return a > b;
        }

        //절댓값 작은 수 우선
        return abs(a) > abs(b);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //연산 개수
    int N;
    cin >> N;

    priority_queue<int,vector<int>,compare> myPQueue;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        
        //0이면 출력
        if(input == 0){
            if(myPQueue.empty()){
                cout << 0 << "\n";
                continue;
            }

            int value = myPQueue.top();
            myPQueue.pop();
            cout << value << "\n";
            
            continue;
        }

        //아니면 입력값 push
        myPQueue.push(input);

    }

}