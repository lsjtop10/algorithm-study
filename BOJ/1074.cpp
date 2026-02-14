#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int powi(int x, int e){
    int res = x;
    for(int i = 0; i < e - 1; i++){
        res *= x;
    }
    return res;
}

int length(int N){
    return powi(2,N);
}

bool isBetween(int val, int a, int b){
    return val >= a && val <= b;
}

int main(){
    int N;
    int r, c = 0;

    cin >> N >> r >> c;
    int val = 0;

    while (N >= 1)
    {
        int loc = 0;
        int half = length(N)/2;
        
        if(isBetween(r, 0, half - 1)){
            if(isBetween(c, 0, half - 1)){ 
                loc = 0; 
            }
            else if(isBetween(c, half, length(N) - 1)){ 
                loc = 1; 
                c = c - half;
            }
        }else if (isBetween(r,half, length(N) - 1)){
            if(isBetween(c, 0, half - 1)){
                loc = 2;
                r = r - half; 
            }else if(isBetween(c, half, length(N) - 1)){
                loc = 3;
                r = r - half;
                c = c - half;
            }
        }
        val += powi(half, 2) * loc;
        N--;
    }

    cout << val;

}
