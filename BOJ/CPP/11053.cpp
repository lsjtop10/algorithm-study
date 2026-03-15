#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> &arr){
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    vector<int> data(num);
    vector<int> dp(num, 1);

    for(int i = 0; i < num; i++){
        cin >> data[i]; 
    }
  

    dp[0] = 1;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < i; j++){
            if(data[i] > data[j]){
                dp[i] = max(dp[i], dp[j] + 1);    
            }
        }
       
    }

    int res = dp[0];
    for(int i = 0; i < num; i++){
        if (res < dp[i]){
            res = dp[i];
        }
    }

    cout << res;

}