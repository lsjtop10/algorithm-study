#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100
int arr[N][N];

int main(){
    int cnt = 1;
    int n; int m;

    scanf("%d %d", &n, &m);

    for(int k = 0; k < m; k++){
        for(int i = 0, j = k; i < n && j >= 0; i++, j--){
            printf("i:%d, j:%d \n", i, j);
            arr[i][j] = cnt;
            cnt++;
        }
        
    }
    
    for(int k = 1; k < n; k++){
        for(int i = k, j = m - 1; i < n && j >= 0; i++, j--){
            printf("i:%d, j:%d \n", i, j);
            arr[i][j] = cnt;
            cnt++;
        }
        
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf(" %2d", arr[i][j]);
        }

        printf("\n");
    }
    
}