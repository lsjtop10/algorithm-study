#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sorted[N];

void merge(int A[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        // 왼쪽을 먼저 처리하는 것이 안정성 때문?
        sorted[k] = A[i] <= A[j] ? A[i++] : A[j++];
        k++;
    }

    // while을 탈출하면
    // i > mid이거나
    // j > right 이다.
    
    // i > mid인 경우
    // j <= right 또는 j >right일 수 있다.

    // j > right인 경우
    // i <= mid 또는 i > mid일 수 있다.

    // i <= min인 경우는 j > right인 경우밖에 없다 -> 왼쪽 남음
    
    // i > mid인 경우 j <= right인 동안 오른쪽에서 가져오면 됨 -> 어차피 j > right인 경우에는 while문 진입하지도 못할 것.


    // 남은 원소는 그냥 복사.
    // 합병정렬 시험에 나올 듯?
    while (i <= mid) {
        sorted[k] = A[i];
        k++;
        i++;
    }

    while (j <= right) {
        sorted[k] = A[j];
        k++;
        j++;
    }

    for (int i = left; i <= right; i++) {
        A[i] = sorted[i];
    }
}

void mergeSort(int A[], int left, int right) {

    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    
    // 중앙 자르고 병합. 퀵정렬과 달리 작은 부분으로 나누고 큰 부분으로 나누는 논리는 없음.
    // 논리를 보면 left, right를
    // left, mid, right로 분할한 다음
    //
    // merge하라는 뜻임. 이때 merge가 left, mid, right를 병합해 정렬된 부분 배열을 만들라는 연산임.
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);

    merge(A, left, mid, right);

    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int A[10];

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
    }

    mergeSort(A, 0, N - 1);
}