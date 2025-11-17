#include <iostream>
#include <bits/stdc++.h>
using namespace std;

constexpr int OPEN = 1; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        stack<int> myStack;
        
        string input;
        cin >> input;

        bool isVPS = true;

        for(int j = 0; j < input.length(); j++){

            if(input[j] == '('){
                myStack.push(OPEN);
            } else if( input[j] == ')' ){
                if(myStack.empty()){
                    isVPS = false;
                    break;
                }
                myStack.pop();
            }
        }

        if(!myStack.empty()){
            isVPS = false;
        }

        if(isVPS){
            cout << "YES" << "\n";    
        }else{
            cout << "NO" << "\n";
        }
        
    }
}