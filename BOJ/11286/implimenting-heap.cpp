#include <iostream>
using namespace std;

const int MAX_HEAP_SIZE = 100000;
int HeapSize = 0;
int HeapDataArr[MAX_HEAP_SIZE + 1];

enum Error{
    Err,
    Ok
};

//힙 관련 함수
void downHeapify(int start);
void upHeapify(int start);
//a가 b보다 큰지 판별하는 함수.
//a > b
bool compare(int a, int b);

//우선순위 큐 관련 함수
Error push(int val);
Error pop();
int top();
bool isEmpty();

//기타 유틸리티 함수
void swap(int* arr, int index1, int index2);


/// @brief a의 우선순위 > b의 우선순위인지 판별한다.
/// @param a 
/// @param b 
/// @return a의 우선순위가 b의 우선순위보다 큰지 여부
bool compare(int a, int b){
//[오답노트] 비교함수의 조건이 반대로 돼어 있었다.
    if(abs(a) == abs(b)){
        return a < b;
    }

    return abs(a) < abs(b);
}

void downHeapify(int start){
    // printHeap();

    //종료 조건:
    //start가 leaf일 때
    if(start > ( HeapSize / 2)){
        return;
    }

    int left = start * 2;
    int right = start * 2 + 1;

    int maxNodeIdx = start;
    //큰 값 찾기

    //[오답 노트] 
    // left, right의 범위 검사 시 실제 HeapSize와 비교해야 한다.
    //안 그러면 데이터가 삽입되지 않았을 때 초기값인 0도 절댓값 비교 대상에 들어간다.
    // [-1 1 0]에서 start = 1인 경우 문제가 된다. 이때는 -1의 right인 0이 절댓값이 가장 작아서 swap이 일어난다.
    // 이에 따라서 최종적으로 [ 0,1,-1]이 될 수 있다.
    //
    //이전: left < MAX_HEAP_SIZE
    if( left <= HeapSize && compare(HeapDataArr[left],HeapDataArr[maxNodeIdx])){
        maxNodeIdx = left;
    }

    if(right <= HeapSize && compare(HeapDataArr[right],HeapDataArr[maxNodeIdx])){
        maxNodeIdx = right;
    }
    
    //내가 가장 큰 값을 갖고 있으면 더 할 거 없음 -> return
    if(maxNodeIdx == start){
        return;
    }

    //교체한 자식에 대해 heapify 실행
    swap(HeapDataArr,start,maxNodeIdx);
    downHeapify(maxNodeIdx);
}

void upHeapify(int start){
    //종료 조건: start가 root이거나
    //swap이 일어나지 않는 경우
    if(start == 1){
        return;
    }
    
    int parenet = start / 2;
    //부모의 우선순위가 더 크면 종료
    if(compare(HeapDataArr[parenet], HeapDataArr[start])){
        return;
    }

    //부모와 자식 값 교체
    swap(HeapDataArr, start, parenet);
    upHeapify(parenet);
}

bool isEmpty(){
    return HeapSize == 0;
}

Error push(int val){

    int insertIdx = HeapSize + 1;
    if(insertIdx >= MAX_HEAP_SIZE){
        return Err;
    }

    //[오답노트] 
    //값을 대입하는 코드가 없었다.
    //
    //이전: 없음 
    HeapDataArr[insertIdx] = val;
    upHeapify(insertIdx);

    //[오답노트] 
    //왜 그런지 모르겠지만 전역 변수에서는 후위 연산자가 잘 안 먹는다.
    //정확한 이유는  추후 확인이 필요하다.
    //
    //이전: Heapsize++; 
    HeapSize += 1;

    return Ok;
}

int top(){
    if(isEmpty()){
        return 0;
    }
    return HeapDataArr[1];
}

Error pop(){
    if(isEmpty()){
        return Err;
    }


    HeapDataArr[1] = 0;
    swap(HeapDataArr, 1, HeapSize);
    //[오답노트] 
    //왜 그런지 모르겠지만 전역 변수에서는 후위 연산자가 잘 안 먹는다.
    //정확한 이유는 추후 확인이 필요하다.
    //
    //이전: Heapsize++; 
    HeapSize -= 1;

    //[오답노트] 
    //downHeapify에 0을 넘기고 있었다. heap은 index가 1부터 시작함.
    //
    //이전: downHeapify(0); 
    downHeapify(1);

    return Ok;
}

void swap(int* arr, int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        
        if(input == 0){
            if(isEmpty()){
                cout << 0 << "\n";
            }else{
                cout << top() << "\n";
                pop();
            }
        }else{;
            push(input);
        }
    }
}