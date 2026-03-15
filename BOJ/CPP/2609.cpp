#include <iostream>
using namespace std;

//최대공약수
int GCD(int a, int b){
    int big = max(a,b);
    int small = min(a,b);

    while (small != 0){
        int r = big % small;
        big = small;
        small = r;
    }
    
    return big;
}

//최소공배수
int MCM(int a, int b){
    int gcd = GCD(a,b);
    
    return gcd * (a / gcd) * (b / gcd); 
}

int main(){
    int a,b;
    cin >> a >> b;

    cout << GCD(a,b) << "\n";
    cout << MCM(a,b) << "\n";
}