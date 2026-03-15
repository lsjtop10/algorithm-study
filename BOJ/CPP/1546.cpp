#include <iostream>
using namespace std;

int main() {
    double max = 0;
    double sum = 0;
    int num;

    cin >> num;
    
    for(int i = 0; i < num; i++){
        int input;
        cin >> input;

        if (max < input){
            max = input;
        }

        sum += input;
    }

    cout << (sum * 100) / (max * num);
}
