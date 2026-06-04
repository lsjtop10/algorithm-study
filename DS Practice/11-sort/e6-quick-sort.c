#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

/*
1. high 루프의 값 비교 조건: A[high] > pivot ➔ A[high] >= pivot (등호 추가)
코드 위치: while (low <= high && A[high] > pivot)

판단: 바꾸면 무한 루프 또는 정렬 오류로 폭발

이유: 앞서 대입해 본 것처럼, 여기에 등호를 넣으면 high가 역주행하다가 0번 방인 피벗(A[left]) 자기 자신을 만났을 때
브레이크를 못 밟고 -1번 방(배열 밖)으로 튕겨 나갑니다. * 게다가 배열에 피벗과 같은 값들이 잔뜩 있을 때([5, 5, 5]),
high가 멈추지 않고 폭주하여 left까지 밀려버리기 때문에 퀵 정렬의 분할 균형이 완벽하게 깨지며 속도가
$\mathcal{O}(N^2)$으로 가라앉거나 무한 루프가 터집니다. 이곳의 등호 제거(>)는 피벗을 안전장치(Sentinel)로 쓰기 위한
절대적인 필수 조건입니다.

2. low 루프의 값 비교 조건: A[low] <= pivot ➔ A[low] < pivot (등호 제거)
코드 위치: while (low <= high && A[low] <= pivot)

판단: 정상 배열에선 돌지만, 중복 데이터 배열에서 무한 루프 폭발

이유: 난수 배열에서는 돌아가겠지만, 모든 원소가 같은 배열([5, 5, 5, 5])이 들어왔을 때 등호가 없으면 low 포인터가 전진을
아예 못 하고 1번 방에 굳어버립니다. 반대편 high도 멈춰 서기 때문에, 두 포인터가 제자리걸음을 하며 영원히 같은 값끼리
스왑만 반복하는 무한 루프에 빠집니다. 피벗과 같은 값을 만나도 밀고 나갈 수 있게 등호(<=)가 반드시 있어야 합니다.

즉 피벗과 비교하는 조건문은 둘 중에 하나는 등호가 포함돼야 한다는 것임.
*/

int partition(int A[], int left, int right) {
    int pivot = A[left];

    int low = left + 1;
    int high = right;
    int tmp;

    while (low < high) {
        // 유효한 index -> pivot과 비교
        // 맞으면 ++
        // 아니면 탈출
        // low <= right로 잡기도 한다.
        // 그러면 low == right일 때 1칸 증가해서 right+1이 되겠으나 상관 없지 않나?
        // 조건이 low < right일 때는
        // low = right일 때 A[low] <= pivot 비교를 수행하는 것이 의미가 있나?
        // 아 이게 뒤 swap 조건이 low < high이기 때문에
        // low가 한 칸 더 가주는 것이 맞을 수도.
        // pivot이 배열의 최댓값이면 
        // low = right+1이고
        // high는 right이기 때문에
        // high 자리에 pivot이 들어간다.
        // 근데 등호가 빠지면 low == high == right 가 될 때는 그 값이 pivot보다 큰지 작은지 체크해야 하는데
        // 그때 체크할 로직이 없다. -> 필요한가? 필요하지. 

        while (low <= high && A[low] <= pivot) {
            low++;
        }

        // 여기에서는 등호 빠지네 -> 왜?
        // high >= left로 잡기도 한다.
        while (low <= high && A[high] > pivot) {
            high--;
        }

        for (int i = 0; i < N; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");

        if (low < high) {
            SWAP(A[low], A[high], tmp);
        }
    }

    SWAP(A[left], A[high], tmp);
    return high;
}

void quickSort(int A[], int left, int right) {

    if (left >= right) {
        return;
    }

    // 피벗보다 작은 값과 큰 값으로 분할
    int q = partition(A, left, right);

    quickSort(A, left, q - 1);
    quickSort(A, q + 1, right);
}

int main() {
    srand(time(NULL));
    int A[10] = {5, 3, 8, 4, 9, 1, 6, 1, 7};

    // for (int i = 0; i < N; i++) {
    //     A[i] = rand() % 100;
    // }

    quickSort(A, 0, N - 1);
}