#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    
    if(a.length() == b.length()){
        return a.compare(b) < 0;
    }else{
        return a.length() < b.length();
    }

}

int main(){
    //stdlib 사용하는 방식으로 구현
    int num;
    cin >> num;

    vector<string> data(num);

    for(int i = 0; i < num; i++){
        cin >> data[i];
    }

    sort(data.begin(), data.end(),compare);
    data.erase(unique(data.begin(), data.end()), data.end());

    for(int i = 0; i < data.size(); i++){
        cout << data[i] << "\n";
    }
}