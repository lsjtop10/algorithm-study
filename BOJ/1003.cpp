#include <bits/stdc++.h>
using namespace std;

array<array<int,3>,41> dp;

int main(){
    dp[1][1] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[0][0] = 1;

    for(int i = 2; i <= 40; i++){
        for(int j = 0; j <= 1; j++){
            dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
        }
    }

    int num;
    cin >> num;

    // for(int i = 0; i < 41; i++){
    //     cout << "i:" << i <<" " << dp[i][0] << " " << dp[i][1] << "\n";
    // }

    for(int i = 0; i < num; i++){
        int input;
        cin >> input;

        cout << dp[input][0] << " " << dp[input][1] << "\n";
    }
}