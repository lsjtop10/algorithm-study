#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false)j;
    cin.tie(0);

    set<int> mySet;
    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        string oper;
        int data;

        cin >> oper;
        if(oper.compare("add") == 0){
            cin >> data;
            mySet.insert(data);
        }else if(oper.compare("remove") == 0){
            cin >> data;
            auto it = mySet.find(data);
            if(it != mySet.end()){
                mySet.erase(it);
            }
        }else if(oper.compare("check") == 0){
            cin >> data;
            auto it = mySet.find(data);
            if(it != mySet.end()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(oper.compare("toggle") == 0){
            cin >> data;
            auto it = mySet.find(data);
            if(it != mySet.end()){
                mySet.erase(it);
            }else{
                mySet.insert(data);
            }
        }else if(oper.compare("all") == 0){
            for(int j = 1; j <= 20; j++){
                mySet.insert(j);
            }
        }else if(oper.compare("empty") == 0){
            mySet.erase(mySet.begin(), mySet.end());
        }
    }
}