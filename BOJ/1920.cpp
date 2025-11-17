#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    cin.tie(0);
    cout.tie(0);
    cout.sync_with_stdio(false);

    int numData;
    cin >> numData;
    vector<int> data(numData);

    for(int i = 0; i < numData; i++){
        cin >> data[i];
    }

    int numQuery;
    cin >> numQuery;
    vector<int> queries(numQuery);
    for(int i = 0; i < numQuery; i++){
        cin >> queries[i];
    }


    sort(data.begin(), data.end());

    for(int i = 0; i < numQuery; i++){

        auto it = lower_bound(data.begin(),data.end(),queries[i]);
        
        if(it == data.end()){
            cout << 0 << "\n";
        }else if(*it != queries[i]){
            // vel이 data의 가장 작은 원소보다도 작은 경우
            cout << 0 << "\n";
        }else{
            cout << 1 << "\n";
        }
    }
    
}