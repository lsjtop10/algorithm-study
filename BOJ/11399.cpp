#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;

    auto data = vector<int>(num,0);

    for(int i = 0; i <num; i++){
        cin >> data[i];
    }

    sort(data.begin(), data.end());

    int ans = 0;
    
    for(int i = 0; i < num; i++){
        ans += data[i]*(num - i);
    }

    cout << ans;
}