#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 100001;

struct Good {
    int weight;
    int value;
};

array<array<int, MAX>, 101> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Good> goods;

    int num;
    int target;

    cin >> num >> target;
    goods.resize(num + 1);

    for(int i = 1; i <= num; i++){
        Good input;

        cin >> input.weight >> input.value;
        goods[i] =  input;
    }

    for(int i = 1; i <= num; i++){
        Good current = goods[i];

        for(int j = 1; j <= target; j++){
            if(current.weight > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = max(dp[i - 1][j], 
                    dp[i - 1][j - current.weight] + current.value);
            }


            // cout << "i: " << i << " j: " << j << "\n";
        }
    }

    int max = 0;
    for(int i = 1; i <= num; i++){
        int val = dp[i][target]; 
        if(max < val){
            max = val;
        }
    }

    cout << max;

}