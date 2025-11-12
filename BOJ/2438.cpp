#include <iostream>
using namespace std;

int main(){
    int lines;
    cin >> lines;

    for(int i = 0; i < lines; i++){
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << "\n";
    }

}