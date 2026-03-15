#include<iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    double res = 1;
    for(int i = 0; i < K; i++){
        res *= ((double)(N - i) / (K - i));
    }

    cout << res;
}