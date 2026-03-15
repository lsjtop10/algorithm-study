#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    cout.tie(0);
    cout.sync_with_stdio(false);    

    for(int i = 1; i <= 9; i++){
        cout << num << " * " << i << " = " << num * i << "\n";
    }
}