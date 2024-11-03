#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int length = 0;
    int sum = 0;

    cin >> length;
    cin >> input;

    for (int i = 0; i < length; i++) {
        sum += input[i] - '0';
    }

    cout << sum;
    
}
