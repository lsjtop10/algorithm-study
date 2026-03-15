#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numOfNums;
    int numOfQuery;

    // 입력
    cin >> numOfNums;
    cin >> numOfQuery;
    //sums[N] = n번째 숫자까지의 합
    vector<int> sums(numOfNums + 1);
    
    int input;
    // 합 배열 계산
    for(int i = 1; i <= numOfNums; i++){
        cin >> input;
        sums[i] = sums[i - 1] + input;
    }
   
    for(int i = 0; i < numOfQuery; i++){
        int start;
        int end;

        cin >> start >> end;
        
        // 출력
        cout << sums[end] - sums[start - 1] << "\n";
    }
}
