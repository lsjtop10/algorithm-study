#include <bits/stdc++.h>
using namespace std;

array<long long, 1001> dp;

int main(){
    int input;
    cin >> input;

    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= input; i++){
        dp[i] = ((dp[i - 2]*2) + dp[i - 1]) % 10007;
    }

    cout << dp[input];
}