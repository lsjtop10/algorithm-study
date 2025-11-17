#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct User{
    int Age;
    string Name;
};

bool compare(User a, User b){
    return a.Age < b.Age;
}

int main(){
    //stdlib 사용하는 방식으로 구현
    int num;
    cin >> num;

    vector<User> data(num);

    for(int i = 0; i < num; i++){
        cin >> data[i].Age;
        cin >> data[i].Name;
    }

    stable_sort(data.begin(), data.end(), compare);

    for(int i = 0; i < data.size(); i++){
        cout << data[i].Age << " " << data[i].Name << "\n";
    }
}