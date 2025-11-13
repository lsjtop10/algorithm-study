#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int target;

    cin >> num;
    cin >> target;

    vector<int> cards(num);

    for(int i = 0; i < num; i++){
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());
    
    int res = 0;
    for(int i = 0; i < num - 2; i++){
        for(int j = i + 1; j < num - 1; j++){

            int remain = target - (cards[i] + cards[j]);

            // cards[k] <= remain인 최대 k 찾기
            auto it = upper_bound(cards.begin() + j + 1, cards.end(), remain);
            
            if (it != cards.begin() + j + 1) {
                --it; // 한 칸 뒤로 (upper_bound가 초과값을 가리킴)
                int sum = cards[i] + cards[j] + *it;
                if (sum <= target) res = max(res, sum);
            }
            
        }
    }

    cout << res;
}