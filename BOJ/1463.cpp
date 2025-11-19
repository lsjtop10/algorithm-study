#include <bits/stdc++.h>
using namespace std;


array<int, 1000001> dp{0};
int main(){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    int input = 0;
    cin >> input;

    for(int i = 4; i <= input; i++){
        int min = i - 1;
        
        if(i % 3 == 0){
            if(dp[min] > dp[i/3]){
                min = i / 3;
            }
        }

        if(i % 2 == 0){
            if(dp[min] > dp[i/2]){
                min = i / 2;
            }
        }

        dp[i] = dp[min] + 1;
    }

    cout << dp[input];

}