#include<iostream>
#include<bits/stdc++.h>
using namespace std;

inline int pow(int a){
    return a * a;
}

int main(){
    vector<int> lines(3);
    
    while (cin >> lines[0] >> lines[1] >> lines[2] 
        && lines[0]+lines[1]+lines[2] != 0 ){
        sort(lines.begin(), lines.end());
        
        if(pow(lines[2]) == pow(lines[0]) + pow(lines[1])){
            cout << "right" << "\n";
        }else{
            cout << "wrong" << "\n";
        }
    }
    
}