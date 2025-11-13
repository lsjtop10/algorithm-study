#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int numPeople;
    vector<int> demandOfSize(6);
    int T, P;

    cin >> numPeople;
    for(int i = 0; i < 6; i++){
        cin >> demandOfSize[i];
    }
    cin >> T >> P;

    int resT = 0;
    for(int i = 0; i < 6; i++){
        if(demandOfSize[i] == 0){
            continue;
        }

        if(demandOfSize[i] % T == 0){
            resT += demandOfSize[i] / T;
        }else{
             resT += (demandOfSize[i] / T) + 1;
        }
    }
    cout << resT << "\n";

    cout << numPeople / P << " " << numPeople  % P;

}
