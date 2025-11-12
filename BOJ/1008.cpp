#include<iostream>
using namespace std;

int main(){
    int a;
    int b;

    cin >> a >> b;

    cout << fixed;
    cout.precision(20);
    
    //소수점 연산이 필요할 때는 형 변환 빼먹지 말기
    cout << (double)a / (double)b;
}