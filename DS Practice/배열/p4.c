#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define N 100

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGNT 4

int arr[100][100];


int main(){
    int n; int m;
    scanf("%d %d", &n, &m);

    int remainRow = n-1; int remainCol = m;

    int i = 0; int j = -1;
    int cnt = 1;
    
    arr[i][j] =1;

    int RowDir = RIGNT;
    int ColDir = DOWN;

    while (true){  

        RowDir == RIGNT ? j++ : j--;
        // i,j부터 RowDir 방향으로 remainCol만큼 cnt를 올리면서 채우기
        for(int k = 0; k < remainCol; k++){
            // printf("i:%d j:%d remainCol: %d\n", i, j, remainCol);   
            arr[i][j] = cnt;
            if(cnt >= n * m){goto EXIT;}
            RowDir == RIGNT ? j++ : j--;
            cnt++;

        }
        
        // RowDir Flip
        RowDir = (RowDir == RIGNT) ? LEFT : RIGNT;
        RowDir == RIGNT ? j++ : j--;

        remainCol--;

        ColDir == DOWN ? i++ : i--;
        // i,j부터 ColDir 방향으로 remainRow만큼 cnt 올리면서 채우기
        for(int k = 0; k < remainRow; k++){
            // printf("i:%d j:%d remainRow: %d\n", i, j, remainCol);
            arr[i][j] = cnt;
            if(cnt >= n * m){goto EXIT;}
            ColDir == DOWN ? i++ : i--;
            cnt++;
        }
        
        // RowDir Flip
        ColDir = (ColDir == DOWN) ? UP : DOWN;
        ColDir == DOWN ? i++ : i--;
        // remainCol--
        remainRow--;

        // 채울 때 cnt가 n * m보다 크면 종료
    }
EXIT:

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }

}