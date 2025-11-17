#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> contents(1);

void swapVec(vector<int> &arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void heapifyUp(int index){
    if(index == 1){
        return;
    }

    int parent = index / 2;
    
    if(contents[parent] > contents[index]){
        swapVec(contents, parent, index);
        return heapifyUp(parent);
    }
    
}

void heapifyDown(int index){


    int left = index * 2;
    int right = index * 2 + 1;
    
    //left == contents.size() - 1 => left만 있고 right는 없는 경우임.
    if( left > contents.size() - 1){
        return;
    }

    int minIndex = left;
    
    if(right < contents.size() && contents[minIndex] > contents[right]){
        minIndex = right;
    }

    if(contents[index] <= contents[minIndex]){
        return;
    }

    swapVec(contents, minIndex, index);
    return heapifyDown(minIndex);

}

//삽입
void insert(int input){
    contents.push_back(input);
    heapifyUp(contents.size() - 1);
}

//삭제

int pop(){
    if(contents.size() <= 1){
        return 0;
    }

    int res = contents[1];

    swapVec(contents, 1, contents.size() - 1);
    contents.pop_back();

    heapifyDown(1);

    return res;

}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numInput;
    cin >> numInput;

    for(int i = 0; i < numInput; i++){
        int oper;
        cin >> oper;
        
        if(oper == 0){
            cout << pop() << "\n";
        }else{
            insert(oper);
        } 

    }

}