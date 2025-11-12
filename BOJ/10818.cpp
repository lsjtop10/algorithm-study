#include <iostream>
using namespace std;

constexpr int MIN_NUM = -1000000;
constexpr int MAX_NUM = 1000000;


int main(){
    
    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);

    // 아이디어는 간단
    // 최댓값: 지금까지 알려진 최댓값보다 더 큰 값
    // 최솟값: 지금까지 알려진 최솟값보다 더 작은 값
    // 이러면 O(n)안에 풀 수 있을 것 같은데
    // 정렬을 하게 되면 O(nlogn)이 돼 버린다.
    int min = MAX_NUM;
    int max = MIN_NUM;
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        int val;
        cin >> val;

        if(min > val){
            min = val;
        }

        if(max < val){
            max = val;
        }
    }

    cout << min << " " << max;
}