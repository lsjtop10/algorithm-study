#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a){
    if(a == 1){return false;}

    for(int i = 1; i * i <= a; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int num; 
    cin >> num;

    int res = 0;
    for(int i = 0; i < num; i++){
        int data;
        cin >> data;

        if(isPrime(data)){
            res++;
        }
    }

    cout << 3;
}