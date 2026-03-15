#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPalindrom(string &str){
    int low = 0;
    int high = str.length() - 1;

    while (low < high){

        // cout << "low: " << low << "\n";
        // cout << "high: " << high << "\n";
        
        //대칭 관계에 있는 문자가 다르면 팰린드롬이 아님
        if(str[low] != str[high]){
            return false;
        }

        low++;
        high--;
    }

    //low==high이거나 low < high인 경우인데 두 경우 모두 팰린드롬임.
    return true;
}

int main(){
// 숫자를 문자로 취급한다.
    while (true)
    {
        string num;
        cin >> num;
        if(num.compare("0") == 0){
            break;
        }

        if(isPalindrom(num)){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
        
    }

}