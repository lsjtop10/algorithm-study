#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<pair<int,int>, vector<pair<int,int>>> pqueue;
    
    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        
        pqueue.push(pair<int,int>(num,i+1));
    }

    auto result = pqueue.top();
    cout << result.first << "\n";
    cout << result.second << "\n";

}