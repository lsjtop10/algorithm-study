#include <bits/stdc++.h>
using namespace std;

int main(){

    int num;
    cin >> num;

    vector<int> inputs(num);
    vector<int> originalData(num);

    for(int i = 0; i < num; i++){
        cin >> inputs[i];
        originalData[i] = inputs[i];
    }

    sort(originalData.begin(), originalData.end());
    originalData.erase(unique(originalData.begin(), originalData.end()), originalData.end());

    map<int,int> coordinateMap;

    for(int i = 0; i < originalData.size(); i++){
        coordinateMap.insert({originalData[i], i});
    }

    for(int i = 0; i < num; i++){
        auto it = coordinateMap.find(inputs[i]);
        int data = it->second;

        cout << data << " ";
    }
}