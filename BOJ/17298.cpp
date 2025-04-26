#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int N;
    cin >> N;

    //초기 배열에 값 입력받기
    vector<int> inputs = vector<int>(N);
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        inputs[i] = input;
    }

    vector<int> result = vector<int>(N, 0);

    stack<int> ngeStack;

    //여기서부터 오큰수 구하기 시작
    ngeStack.push(0);

    // for i : 1 to i - 1
    for (int i = 1; i < N; i++){
    // 1. input[i] > input[stack의 top]이면 top의 오큰수는 input[i]이다
        while (!ngeStack.empty() && inputs[i] > inputs[ngeStack.top()]){
            result[ngeStack.top()] = inputs[i];
    // 2. stack에서 해당 원소를 pop하고 다시 비교한다.
            ngeStack.pop();
        }

    // 3. input[n] <= input[stack의 top]이 되면 n을 push한다.
        ngeStack.push(i);
    }

    //모든 원소를 대상으로 비교했는데도 없는 경우는 오큰수 없는 거임
    while(!ngeStack.empty()){
        result[ngeStack.top()] = -1;
        ngeStack.pop();
    }

    for(auto e : result){
        cout << e << " ";
    }

}

