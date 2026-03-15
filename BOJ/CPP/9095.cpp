#include <iostream>
#include <bits/stdc++.h>
using namespace std;

array<int, 12> dp;


int main(){
    dp[1] = 1; // 1
    dp[2] = 2; // 1+1 2
    dp[3] = 4; //3 2+1 1+1+1 1+2

    int num;
    cin >> num;

    for(int i = 4; i <= 12; i++){
        dp[i] = dp[i-1]  + dp[i-2]  + dp[i-3];
    }

    for(int i = 0; i < num; i++){
        int in;
        cin >> in;

        cout << dp[in] << "\n";
    }
    
}