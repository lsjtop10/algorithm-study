#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Point{
    int X;
    int Y;
};

bool compare(Point a, Point b){
    if(a.X == b.X){
        return a.Y < b.Y;
    }
    return a.X < b.X;
}

int main(){
    int num;
    cin >> num;

    vector<Point> data(num);

    for(auto it = data.begin(); it != data.end(); it++){
        int x, y;
        cin >> x >> y;

        (*it).X = x;
        it->Y = y;
    }

    sort(data.begin(), data.end(), compare);
    
    for(auto e : data){
        cout << e.X << " " << e.Y << "\n";
    }
}