//최종 제출 코드
#include <iostream>
#include <vector>

using namespace std;

void scanArr(vector<int> &arr, int n);
void printArr(vector<int> &arr);
void heapify(vector<int> &heap, int index, int size);
void swapElement(vector<int> &arr, int from, int to);
//퀵소트 알고리즘 사용
void sortArr(vector<int> &arr);

int main(int argc, char* argv[]) {
	vector<int> data;
	int num = 0;
	//N개의 수를 입력받기
	
	cin >> num;
	data.push_back(0);
	scanArr(data, num);
	sortArr(data);
	printArr(data);
	
}


void sortArr(vector<int> &arr){

	//힙에 들어있는 노드 원소의 개수
	int size = arr.size() - 1;
	
	//주어진 임의의 배열을 heap으로 만든다. leaf node에 대해서는 heapify 연산을 수행하지 않는다.
	// *작은 단위부터 heap으로 만든다. 
	for(int i = 0; i < size / 2; i++){
		heapify(arr, size / 2 -  i, size);
	}
	
	while(size > 0){
		swapElement(arr, 1, size);
		heapify(arr, 1, size - 1);
		size--;
	}

}

// heap의 index는 heap의 root node를 1이라고 하고
// 같은 level에서는 왼쪽이 작은 index를 갖는다.
void heapify(vector<int> &heap, int index, int size){
	if (index > (size / 2)){ return;}
	
	int left = 2 * index;
	int right = 2 * index + 1;
	
	int largest = index;
	
	if ( left <= size && heap[left] > heap[largest]){
		largest = left;
	}
	if ( right <= size && heap[right] > heap[largest]){
		largest = right;
	}
	
	if(largest != index){
		swapElement(heap, index,largest);
		return heapify(heap, largest, size);
	}
	
}


void printArr(vector<int> &arr){
	
	for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++){
        if (iter == arr.begin()){
            continue;
        }
		cout << *iter << endl;
	}
}

void scanArr(vector<int> &arr, int n){

	for (int i = 0; i < n; i++){
		int in = 0;
		cin >> in;
		arr.push_back(in);
	}
	
}

void swapElement(vector<int> &arr, int from, int to){
	int temp = arr[from];
	arr[from] = arr[to];
	arr[to] = temp;
}
