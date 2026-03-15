#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cout.sync_with_stdio(false);

    int num;
    cin >> num;

    int repeat;
    string str;

    for(int i = 0; i < num; i++){
        cin >> repeat >> str;
        for(int j = 0; j < str.length(); j++){
            for(int k = 0; k < repeat; k++){
                cout << str[j];
            }  
        }
        cout << "\n";
    }
}