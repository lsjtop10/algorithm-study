#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

int BST[N];

void insertKey(int rootIdx, int key){
    while (true)
    {
        //rootIdx가 N을 넘어가는 경우가 배열이 꽉 차있는 경우라고 단정하면 안 됨.
        // 편향 이진트리 되면 쉽게 배열의 IDX를 넘을 수 있음. 
        if(rootIdx >= N){
            printf("overflow");
            return;
        }

        // 탐색 실패 == 키의 자리
        if(BST[rootIdx] == 0){
            BST[rootIdx] = key;
            return;
        }

        // 탐색 범위를 좁히는 과정
        if(key < BST[rootIdx]){
            rootIdx = rootIdx * 2;
        }else if(key > BST[rootIdx]){
            rootIdx = rootIdx * 2 + 1;
        }else{
            return;
        }
    }
    
}

int preOrder(int rootIdx){
    if(BST[rootIdx] != 0){
        printf("[%d] ", BST[rootIdx]);
        preOrder(rootIdx * 2);
        preOrder(rootIdx * 2 + 1);
    }
}

// 삭제
// 노드 개수 세기
// 노드 높이 세기

int main(){
    int keys[] = {35,18,7,26,12,3,68,22,30,99};

    for(int i = 0; i < 10; i++){
        insertKey(1, keys[i]);
    }

    printf("Pre: "); preOrder(1);
}