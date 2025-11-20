#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    set<string> notListenedPerson;
    vector<string> res;


    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;

        notListenedPerson.insert(input);
    }

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;

        if(notListenedPerson.find(input) != notListenedPerson.end()){
            res.push_back(input);
        }
    }

    sort(res.begin(), res.end());
    
    cout << res.size();
    cout << "\n";
    for(string e : res){
        cout << e << "\n";
    }

}